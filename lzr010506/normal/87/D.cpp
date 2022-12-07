#include <bits/stdc++.h>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = a; i < b; i++)
#define RFOR(i, a, b) for(i = a - 1; i >= b; i--)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size()) 
#define ALL(a) (a).begin(),(a).end() 
#define PB push_back
#define MP make_pair
#define fst first
#define sec second
int P[1 << 18], B[1 << 18], C[1 << 18], S[1 << 18];
Int R[1 << 18];
vector<PII> E[1 << 18];
int gMark, gS;

int Parent(int a)
{
	if(P[a] == a)
		return a;

	return P[a] = Parent(P[a]);
}

void dfs(int a, int p)
{
	B[a] = gMark;

	int i;
	FOR(i, 0, SIZE(E[a]))
	{
		int b = E[a][i].fst;
		if(b == p)
			continue;

		dfs(b, a);
		S[a] += S[b];
	}

	S[a] += C[a];
}

void dfs2(int a, int p)
{
	B[a] = gMark;

	int i;
	FOR(i, 0, SIZE(E[a]))
	{
		int b = E[a][i].fst;
		if(b == p)
			continue;

		dfs2(b, a);
		Int s = S[b];
		R[ E[a][i].sec ] = s*(gS - s);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	int i, j;
	vector< pair<PII, PII> > v;
	FOR(i, 0, n - 1)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		v.PB(MP(PII(c, i), PII(a - 1, b - 1)));
	}

	sort(ALL(v));

	FOR(i, 0, n + n)
	{
		P[i] = i;
		C[i] = 1;
		S[i] = 0;
	}

	CLEAR(B, 0);
	gMark = 0;

	int prev = 0;
	int cnt = n;
	FOR(i, 1, n)
		if(i == n - 1 || v[i].fst.fst != v[i - 1].fst.fst)
		{
			FOR(j, prev, i)
			{
				int a = Parent(v[j].sec.fst);
				int b = Parent(v[j].sec.sec);

				E[a].PB(PII(b, v[j].fst.sec));
				E[b].PB(PII(a, v[j].fst.sec));
			}

			++gMark;
			FOR(j, prev, i)
			{
				int a = Parent(v[j].sec.fst);
				if(B[a] != gMark)
					dfs(a, -1);
			}

			++gMark;
			FOR(j, prev, i)
			{
				int a = Parent(v[j].sec.fst);
				if(B[a] != gMark)
				{
					gS = S[a];
					dfs2(a, -1);
				}
			}

			FOR(j, prev, i)
			{
				int a = Parent(v[j].sec.fst);
				int b = Parent(v[j].sec.sec);

				P[a] = P[b] = cnt;
				C[cnt] = C[a] + C[b];
				++cnt;
			}

			prev = i;
		}

	Int res = 0;
	FOR(i, 0, n - 1)
		res = max(res, R[i]);

	VInt ret;
	FOR(i, 0, n - 1)
		if(R[i] == res)
			ret.PB(i + 1);

	printf("%I64d %d\n", res + res, SIZE(ret));
	FOR(i, 0, SIZE(ret))
		printf("%d%c", ret[i], i == SIZE(ret) - 1 ? '\n' : ' ');

	return 0;
};