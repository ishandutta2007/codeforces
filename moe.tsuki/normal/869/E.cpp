#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(x) begin(x),end(x)
#define F(i,n) for (int i = 0; i < n; ++i)
#define F1(i,n) for (int i = 1; i <= n; ++i)
#define dbg(x) cerr << #x << " = " << x << endl
#define dbgg(x) cerr << #x << " = " << x << ' '
#define T(x) x[pool]
#define mineq(x,y) { if ((x) > (y)) (x) = (y); }
#define maxeq(x,y) { if ((x) < (y)) (x) = (y); }
#define MEOW cout << "meowwwww" << '\n'; system("pause");
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int, int> pii;

template<typename T>
ostream& operator <<(ostream &s, const vector<T> &c)
{
	s << "[ "; for (auto it : c) s << it << " "; s << "\b]\n";
	return s;
}

template<typename T>
ostream& operator <<(ostream &s, const pair<int, T> &c)
{
	s << "[ "; cout << c.fi << " , " << c.se << " ] ";
	return s;
}

const int maxn = 3456, maxq = 123456;
int n, m, q, bit1[maxn][maxn], bit2[maxn][maxn];
pii oper[maxq];
map<pair<pii, pii>, int> nyon;

#define lowbit(x) (x & (-(x)))

void add(int x, int y, pii v)
{
	while (x < maxn)
	{
		int yy = y;
		while (yy < maxn)
		{
			//dbgg(x); dbg(yy);
			bit1[x][yy] += v.fi;
			bit2[x][yy] += v.se;
			//dbg(bit[x][yy]);
			yy += lowbit(yy);
		}
		x += lowbit(x);
	}
}

pii qry(int x, int y)
{
	pii ret; ret.first = ret.second = 0;
	while (x)
	{
		int yy = y;
		while (yy)
		{
			ret.fi += bit1[x][yy];
			ret.se += bit2[x][yy];
			//dbg(ret);
			yy -= lowbit(yy);
		}
		x -= lowbit(x);
	}
	return ret;
}

pii myrand()
{
	return mp((rand() << 10) + rand(), (rand() << 10) + rand());
}

void input()
{
	//ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> q;
}
void solve()
{
	/*while(true)
	{
		dbg(myrand()); MEOW;
	}*/
	srand(time(NULL));
	int r1, c1, r2, c2;
	for (int i = 1; i <= q; ++i)
	{
		int cmd; cin >> cmd;
		if (cmd == 1)
		{
			cin >> r1 >> c1 >> r2 >> c2;
			nyon[mp(mp(r1, c1), mp(r2, c2))] = i;
			pii cur = myrand();
			pii mcur = cur; mcur.first *= -1; mcur.second *= -1;
			add(r1    , c1    ,  cur);
			add(r2 + 1, c1    , mcur);
			add(r1    , c2 + 1, mcur);
			add(r2 + 1, c2 + 1,  cur);
			oper[i] = cur;
		} else if (cmd == 2)
		{
			cin >> r1 >> c1 >> r2 >> c2;
			int ind = nyon[mp(mp(r1, c1), mp(r2, c2))];
			pii cur = oper[ind];
			pii mcur = cur; mcur.first *= -1; mcur.second *= -1;
			add(r1    , c1    , mcur);
			add(r2 + 1, c1    ,  cur);
			add(r1    , c2 + 1,  cur);
			add(r2 + 1, c2 + 1, mcur);
		} else 
		{
			cin >> r1 >> c1 >> r2 >> c2;
			if (qry(r1, c1) == qry(r2, c2)) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}

main()
{
	input();
	solve();
}