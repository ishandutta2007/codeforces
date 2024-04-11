#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>
#define y1 y11
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define mt make_tuple
#define NAME ""

using namespace std;
	
typedef long long ll;
typedef long double ld;

const ld PI = acos(-1.0);

struct node
{
	node* l;
	node* r;	
	int flag;
	int cnt;
};


typedef node* pnode;

pnode newnode()
{
    pnode nn = new node();
	nn->l = nn->r = NULL;
	nn->flag = -1;
	return nn;
}

void push(pnode v, int sv)
{
	if (!(v->l)) v->l = newnode();
	if (!(v->r)) v->r = newnode();
	if (v->flag != -1)
	{
		v->l->flag = v->r->flag = v->flag;
		v->l->cnt = ((sv + 1) / 2) * v->flag;
		v->r->cnt = (sv / 2) * v->flag;
		v->flag = -1;
	}
}


const int MAXN = 150001;

typedef  pair <pair <int, int>, int> ppt;
set <ppt> st;
typedef set <ppt>::iterator siter;
int n, m, p;
int rmq[4 * MAXN];
int cnt[MAXN];
int calc[MAXN];
int ver[MAXN];
int curver = 0;
vector <int> curans;
vector <ppt> curadd;
int need;
pnode root[MAXN];
int lv, rv, vl;
const int SQ = 3501;

struct cmpsize
{
	bool operator()(int x, int y)
	{
		return mp(cnt[x], x) > mp(cnt[y], y);
	}
};

set <int, cmpsize> sizest;
typedef set <int, cmpsize>::iterator sizeiter;

int get_rmq(pnode v, int l, int r)
{
	if ((lv <= l) && (r <= rv)) return v->cnt;
	if ((lv > r) || (l > rv)) return 0;
	if (v->flag != -1) return (v->flag) * (min(r, rv) - max(l, lv) + 1);
	return get_rmq(v->l, l, (l + r) / 2) + get_rmq(v->r, (l + r) / 2 + 1, r);
}

void modify_rmq(pnode v, int l, int r)
{
	if ((lv > r) || (l > rv)) return;
	if ((lv <= l) && (r <= rv))
	{
		v->flag = vl;
		v->cnt = vl * (r - l + 1);
		return;
	}
	push(v, r - l + 1);
	modify_rmq(v->l, l, (l + r) / 2);
	modify_rmq(v->r, (l + r) / 2 + 1, r);
	v->cnt = v->l->cnt + v->r->cnt;
}

inline void push_main(int v)
{
	if (rmq[v] != 0)
	{
		rmq[v * 2 + 1] = rmq[v * 2 + 2] = rmq[v];
		rmq[v] = 0;
	}
}

void go_main(int v, int l, int r)
{
	if ((l > rv) || (lv > r)) return;
	if (rmq[v] != 0)
	{
		int cl = rmq[v], cn = min(r, rv) - max(l, lv) + 1;
		if (ver[cl] != curver) ver[cl] = curver, calc[cl] = 0;
		if (calc[cl] >= need) return;
		calc[cl] += cn;
		if (calc[cl] >= need) curans.push_back(cl);
		return;
	}
	go_main(v * 2 + 1, l, (l + r) / 2);
	go_main(v * 2 + 2, (l + r) / 2 + 1, r);
}

void modify_main(int v, int l, int r)
{
	if ((l > rv) || (lv > r)) return;
	if ((lv <= l) && (r <= rv))
	{
		rmq[v] = vl;
		return;
	}
	push_main(v);
	modify_main(v * 2 + 1, l, (l + r) / 2);
	modify_main(v * 2 + 2, (l + r) / 2 + 1, r);
}


void gain(int x, int l, int r)
{
	sizest.erase(x);
	cnt[x] += (r - l + 1);
	lv = l, rv = r, vl = x;
	modify_main(0, 1, n);
	vl = 1;
	modify_rmq(root[x], 1, n);
	sizest.insert(x);
	st.insert(mp(mp(l, r), x));
}

void lose(int x, int l, int r)
{
	sizest.erase(x);
	cnt[x] -= (r - l + 1);
	lv = l, rv = r, vl = 0;
	modify_rmq(root[x], 1, n);
	sizest.insert(x);
}


int main()
{
   //freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin >> n >> m >> p;
	memset(cnt, 0, sizeof(cnt));
	memset(calc, 0, sizeof(calc));
	memset(ver, 0, sizeof(ver));
	memset(rmq, 0, sizeof(rmq));
	for (int i = 0; i < MAXN; i++)
	{
		root[i] = newnode();
		lv = 1, rv = n, vl = 0;
		modify_rmq(root[i], 1, n);
		sizest.insert(i);
	}
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		gain(x, i, i);
	}
	for (int iter = 0; iter < m; iter++)
	{
		int tp, l, r;
		cin >> tp >> l >> r;
		if (tp == 1)
		{
			int x;
			cin >> x;
			curadd.clear();
			siter it = st.lower_bound(mp(mp(l + 1, 0), 0));
			it--;
			if (it->fs.sc >= r)
			{
				if (it->fs.fs != l)
				{
					curadd.push_back(*it);
					curadd[curadd.size() - 1].fs.sc = l - 1;
				}
				if (it->fs.sc != r)
				{
					curadd.push_back(*it);
					curadd[curadd.size() - 1].fs.fs = r + 1;
				}
				lose(it->sc, l, r);
				st.erase(it);
			}
			else
			{
				lose(it->sc, l, it->fs.sc);
				if (it->fs.fs != l)
				{
					curadd.push_back(*it);
					curadd[curadd.size() - 1].fs.sc = l - 1;
				}
				siter it2 = it;
				it2++;
				while (it2->fs.sc < r) 
				{
					if (it2 != it)  lose(it2->sc, it2->fs.fs, it2->fs.sc);
					it2++;
				}
				lose(it2->sc, it2->fs.fs, r);
				if (it2->fs.sc != r)
				{
					curadd.push_back(*it2);
					curadd[curadd.size() - 1].fs.fs = r + 1;
				}
				it2++;
				st.erase(it, it2);
			}
			for (int i = 0; i < curadd.size(); i++)
			{
				st.insert(curadd[i]);
			}
			gain(x, l, r);
		}
		else
		{
			curans.clear();
			need = ((r - l + 1) * p + 99) / 100;
			if (r - l > SQ)
			{
				for (sizeiter it = sizest.begin(); (it != sizest.end()) && (cnt[*it] >= need); it++)
				{
					lv = l, rv = r;
					if (get_rmq(root[*it], 1, n) >= need) curans.push_back(*it);
				}
			}
			else
			{
				curver++;
				lv = l, rv = r;
				go_main(0, 1, n);
			}
			cout << curans.size();
			for (int i = 0; i < curans.size(); i++) cout << " " << curans[i];
			cout << '\n';
		}
	}
	return 0;
}