#include <bits/stdc++.h>
#define FOR(i, x, y) for(int i = (x); i <= (y); i ++)
#define ins insert
using namespace std;
#define N 500010
set<int> SS[2000000];
map<int,int> MP;
int n, A[N], C, rs[N], nm;
bool ch[2000010];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int Find(int x)
{
	int& w = MP[x];
	if(!w) w = ++ C;
	return w;
}

bool check(int pp, bool camp = 0)
{
	FOR(i, 1, C) ch[i] = 0;
	FOR(i, 1, n)
	{
		nm = 0;
		for(int j = A[i]; j; j = j >> 1) rs[++ nm] = j;
		bool flag = 0;
		FOR(j, 1, nm)
		{
			if(rs[j] > pp) continue;
			int x = Find(rs[j]);
			if(ch[x]) continue;
			ch[x] = 1;
			if(camp) printf("%d ",rs[j]);
			flag = 1;
			break;
		}
		if(!flag) return 0;
	}
	return 1;
}
int main()
{
	n = read();
	FOR(i, 1, n)
	{
		A[i] = read();
		nm = 0;
		for(int j = A[i]; j; j = j >> 1) rs[++ nm] = j;
		FOR(j, 1, nm)
		{
			int x = Find(rs[j]);
			SS[x].ins(A[i]);
		}
	}
	int l = 0, r = 1e9 + 3;
	while(l < r)
	{
		int mid = (l + r) >> 1;
		if(check(mid)) r = mid; 
		else l = mid + 1;
	}
	check(l, 1);
	return 0;
}