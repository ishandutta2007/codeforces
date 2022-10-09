#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 2e9+9091203;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 600100
PII tab[maxn];
int n, T, m, c, DL = 0;
priority_queue <int, vector <int>, greater <int> > pq;

int L, N;

int h1[maxn], h2[maxn];

bool answer(int k)
{
	T = 1;
	while (T--)
	{
		while (!pq.empty()) pq.pop();
		n = N; m = N;
		DL = 0;
		for (int i=1; i<=m; ++i)
		{
			int where = h1[i - 1];
			int x = 0, y = N + N + N;
			while (x < y)
			{
				int sr = (x + y) / 2;
				if (where - h2[sr] > k) x = ++sr;
				else y = sr;
			}
			
			int a = x;
			x = 0, y = N + N + N;
			while (x < y)
			{
				int sr = (x + y) / 2 + 1;
				if (h2[sr] - where > k) y = --sr;
				else x = sr;
			}
			int b = x;
			
			if (a > b) return 0; //nie da sie zadnego przyporzadkowac
			if (b - a + 1 >= N)
			{
				a = 0;
				b = N - 1;
			}
			a %= N; b %= N;
			if (a <= b) tab[++DL] = mp(a, b), tab[++DL] = mp(a + n, b + n);
			else tab[++DL] = mp(a, b + n);
		}

		int akt = 0, wsk = 1;
		sort(tab + 1, tab + DL + 1);
		///for (int i=1; i<=DL; ++i) printf("%d %d\n", tab[i].e1, tab[i].e2);
		tab[DL + 1] = mp(inf, 0);
		while (akt != inf)
		{
			while (tab[wsk].e1 <= akt) pq.push(tab[wsk].e2), ++wsk;
			if (pq.empty())
			{
				akt = tab[wsk].e1;
				continue;
			}
			//printf("%d %d\n", akt, pq.top());
			if ((!pq.empty()) && pq.top() < akt) return 0;
			pq.pop();
			++akt;
			if ((!pq.empty()) && pq.top() < akt) return 0;
			
		}
		return 1;
	}
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin >> N >> L;
	for (int i=0; i<N; ++i) cin >> h1[i];
	sort(h1, h1+N);
	for (int i=N; i<N+N; ++i) cin >> h2[i];
	sort(h2+N, h2+N+N);
	for (int i=0; i<N; ++i) 
	{
		h2[i + N + N] = h2[i + N] + L;
		h2[i] = h2[i + N] - L;
	}
	//cout << answer(1) << endl;
	int xx = 0, yy = inf;
	while (xx < yy)
	{
		int mid = ((xx + yy) >> 1);
		if (!answer(mid)) xx = ++mid;
		else yy = mid;
	}
	cout << xx;
}