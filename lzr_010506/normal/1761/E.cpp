#include <bits/stdc++.h>
using namespace std;

#define WA printf("line = %d\n" , __LINE__);

const int Max_n = 4005;

int read()
{
	int x;
	scanf("%d" , &x);
	return x;
}

int n , fa[Max_n];

int find(int x)
{
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void merge(int x , int y)
{
	if(find(x) == find(y)) return;
	fa[find(x)] = find(y);
}

char c[Max_n][Max_n];

int st[Max_n] , tp , tuan[Max_n] , p;

bool vis[Max_n] , out;

void dfs(int now)
{
	if(out) return;
	if(!vis[now]) vis[now] = true;
	int nex = 0;
	for(int i = 1 ; i <= n ; ++ i)
		if(c[now][i] == '1')
		{
			if(!vis[i]) dfs(i) , ++ nex;
			if(out) return;
		}
	if(nex == 0) printf("%d\n" , now) , out = true;
}

void check(int x)
{
	tp = p = 0;
	for(int i = 1 ; i <= n ; ++ i)
		if(find(i) == x)
			st[ ++ tp] = i;
	tuan[ ++ p] = st[1];
	for(int i = 2 ; i <= tp ; ++ i)
	{
		bool wqqka = true;
		for(int j = 1 ; j <= p ; ++ j)
			if(c[st[i]][tuan[j]] == '0')
				wqqka = false;
		if(wqqka) tuan[ ++ p] = st[i];
	}
	for(int i = 1 ; i <= n ; ++ i)
		vis[i] = false;
	for(int i = 1 ; i <= p ; ++ i)
		vis[tuan[i]] = true;
	puts("1");
	out = false;
	for(int i = 1 ; i <= p ; ++ i)
	{
		dfs(tuan[i]);
		if(out) break;
	}
}

void solve()
{
	n = read();
	for(int i = 1 ; i <= n ; ++ i)
		fa[i] = i;
	for(int i = 1 ; i <= n ; ++ i)
	{
		scanf("%s" , c[i] + 1);
		for(int j = 1 ; j <= n ; ++ j)
		if(c[i][j] == '1') merge(i , j);
	}
	int cnt = 0;
	for(int i = 1 ; i <= n ; ++ i)
		if(find(i) == i) ++ cnt;
	if(cnt == 1) return puts("0") , void();
	for(int i = 1 ; i <= n ; ++ i)
	{
		int cnt = 0;
		for(int j = 1 ; j <= n ; ++ j)
			cnt += c[i][j] - '0';
		if(cnt == 0)
		{
			puts("1");
			printf("%d\n" , i);
			return;
		}
	}
	// WA;
	cnt = 0;
	for(int i = 1 ; i <= n ; ++ i)
	if(find(i) == i)
	{
		int d = 0;
		for(int j = 1 ; j <= n ; ++ j)
		if(find(j) == i) ++ d;
		bool wqqka = true;
		for(int j = 1 ; j <= n ; ++ j)
		if(find(j) == i)
		{
			int dag = 0;
			for(int k = 1 ; k <= n ; ++ k)
				if(c[j][k] == '1')
					++ dag;
			if(dag != d - 1) wqqka = false;
		}
		if(!wqqka)
		{
			// WA;
			check(i); return;
		}
		else ++ cnt;
	}
	if(cnt == 2)
	{
		int sz[2] , t[2];
		sz[0] = sz[1] = 0;
		for(int i = 1 ; i <= n ; ++ i)
		if(find(i) == i)
		{
			if(sz[0] == 0)
			{
				t[0] = i;
				for(int j = 1 ; j <= n ; ++ j)
					if(find(j) == i) ++ sz[0];
			}
			else
			{
				t[1] = i;
				for(int j = 1 ; j <= n ; ++ j)
					if(find(j) == i) ++ sz[1];
			}
		}
		if(sz[0] > sz[1]) swap(sz[0] , sz[1]) , swap(t[0] , t[1]);
		printf("%d\n" , sz[0]);
		for(int i = 1 ; i <= n ; ++ i)
		if(find(i) == t[0])
			printf("%d " , i);
		puts("");
		return;
	}
	puts("2");
	int tt = 0;
	for(int i = 1 ; i <= n ; ++ i)
	if(find(i) == i)
	{
		++ tt;
		printf("%d\n" , i);
		if(tt == 2) break;
	}
	puts("");
}

int main()
{
	for(int T = read() ; T ; -- T)
		solve();
}
/*
1
4
0100
1000
0001
0010
*/