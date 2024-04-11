#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <functional>
#include <sstream>
#include <fstream>
#include <valarray>
#include <complex>
#include <queue>
#include <cassert>
#include <bitset>
using namespace std;

#ifdef LOCAL
#define debug_flag true
#else
#define debug_flag false
#endif

#define dbg(args...) { if (debug_flag) { _print(_split(#args, ',').begin(), args); cerr << endl; } else { void(0);} }

vector<string> _split(const string& s, char c) {
	vector<string> v;
	stringstream ss(s);
	string x;
	while (getline(ss, x, c))
		v.emplace_back(x);
	return v;
}

void _print(vector<string>::iterator) {}
template<typename T, typename... Args>
void _print(vector<string>::iterator it, T a, Args... args) {
	string name = it -> substr((*it)[0] == ' ', it -> length());
	if (isalpha(name[0]))
		cerr << name  << " = " << a << " ";
	else
		cerr << name << " ";
	_print(++it, args...);
}

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42;
#endif

typedef long long int int64;


const int N = (int) 1e5 + 100;
int gcnt[N];
int a[N];
const int X = 400;
vector <int> lists[X];
int listOwnewrs[X];
int cntLists;
const int BIG_SZ = X;
const int BLOCK = X;

int getCntInList(int id, int l, int r)
{
	return lower_bound(lists[id].begin(), lists[id].end(), r) - lower_bound(lists[id].begin(), lists[id].end(), l);
}

struct Qu
{
	int id, l, r;
	Qu() : id(), l(), r() {}
	Qu(int _id, int _l, int _r) : id(_id), l(_l), r(_r) {}

	bool operator < (const Qu &A) const
	{
		return r < A.r;
	}
};
Qu qu[N];
vector <Qu> qus[X];
int answer[N];

int cnt[N], cntOfCnt[X];


void init()
{
	memset(cnt, 0, sizeof cnt);
	memset(cntOfCnt, 0, sizeof cntOfCnt);
}

void addElement(int x)
{
	if (x == -1) return;
	cntOfCnt[cnt[x] ]--;
	cnt[x]++;
	cntOfCnt[cnt[x] ]++;
}

void delElement(int x)
{
	if (x == -1) return;
	cntOfCnt[cnt[x] ]--;
	cnt[x]--;
	cntOfCnt[cnt[x] ]++;
}

pair <int, int> huf[N], auf[N];
int hsz, asz;

int Huf(int l, int r)
{
	l--;
	r--; //WTF
	asz = 0;
	int hl = 0, al = 0;
	int ans = 0;
	while (hl < hsz || al < asz)
	{
		pair <int, int> b;
		if (al == asz || (hl < hsz && huf[hl] < auf[al] ) )
		{
			b = huf[hl++];
		}
		else
		{
			b = auf[al++];
		}
		if (b.second > 1)
		{
			ans += b.second / 2 * b.first * 2;
			auf[asz++] = make_pair(b.first * 2, b.second / 2);
			if (b.second & 1)
			{
				if (al > 0)
					auf[--al] = make_pair(b.first, 1);
				else
					huf[--hl] = make_pair(b.first, 1);
			}
			continue;
		}
		if (hl == hsz && al == asz) break;
		
		if (al == asz || (hl < hsz && huf[hl] < auf[al] ) )
		{
			ans += b.first + huf[hl].first;
			auf[asz++] = make_pair(b.first + huf[hl].first, 1);
			huf[hl].second--;
			if (huf[hl].second == 0) hl++;
		}
		else
		{
			ans += b.first + auf[al].first;
			auf[asz++] = make_pair(b.first + auf[al].first, 1);
			auf[al].second--;
			if (auf[al].second == 0) al++;
		}
	}
	return ans;// + r - l;
}


int getAns(int l, int r)
{
	hsz = 0;
	for (int i = 1; i < X; i++)
		if (cntOfCnt[i] != 0)
			huf[hsz++] = make_pair(i, cntOfCnt[i] );

	for (int i = 0; i < cntLists; i++)
	{
		int cur = getCntInList(i, l, r);
		if (cur != 0)
			huf[hsz++] = make_pair(cur, 1);
	}
	sort(huf, huf + hsz);

//	eprintf("[%d, %d) : ", l, r);
//	for (int i = 0; i < hsz; i++)
//		eprintf(", %d x%d", huf[i].first, huf[i].second);
//	eprintf("\n");


	return Huf(l, r);
}

int main()
{
#ifdef LOCAL
	freopen ("in.txt", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		gcnt[a[i] ]++;
	}
	for (int i = 0; i < N; i++)
		if (gcnt[i] >= X)
		{
			listOwnewrs[cntLists++] = i;
			for (int j = 0; j < n; j++)
				if (a[j] == i)
				{
					a[j] = -1;
					lists[cntLists - 1].push_back(j);
				}
		}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int l, r;
		scanf("%d %d", &l, &r);
		l--;
		qu[i] = Qu(i, l, r);
		qus[l / BLOCK].push_back(qu[i] );
	}

	for (int id = 0; id * BLOCK < n; id++)
	{
		init();

		int bound = id * BLOCK;
		sort(qus[id].begin(), qus[id].end() );
		int pos = 0;

		for (int r = bound; r <= n; r++)
		{
			while (pos < (int) qus[id].size() && qus[id][pos].r == r)
			{
				while (bound > qus[id][pos].l)
					addElement(a[--bound] );
				while (bound < qus[id][pos].l)
					delElement(a[bound++] );
				
				answer[qus[id][pos].id] = getAns(qus[id][pos].l, qus[id][pos].r);

				pos++;
			}
			
			addElement(a[r] );
		}
	}

	for (int i = 0; i < q; i++)
		printf("%d\n", answer[i] );


	return 0;
}