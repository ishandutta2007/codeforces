#include <bits/stdc++.h>
#define N 300010
#define lmt 800
using namespace std;

struct Node
{
	int to[26], val;
}t[N];

vector<int> nxt[N];
string s[N], ch;
int val[N], ra[N], m, cnt, mf, tot;
void Work1()
{
	cnt ++;
	cin >> ch;
	val[cnt] = 1;
	if (ch.size() <= lmt)
	{
		int nt = 1;
		for(int j = 0,l = ch.size(); j < l; j ++)
		{
			int x = ch[j] - 'a';
			if (!t[nt].to[x]) tot ++, t[nt].to[x] = tot;
			nt = t[nt].to[x];
		} 
		t[nt].val ++;
	} 
	else     
	{
		ra[++ mf] = cnt;
		s[mf] = ch;
		int n = ch.size();
		nxt[mf].resize(n);
		nxt[mf][0] = -1;
		for(int p = 1,j = -1; p < n; p ++)
		{
			for(;j != -1 && ch[p] != ch[j + 1]; j = nxt[mf][j]);
			if (ch[p] == ch[j + 1]) j ++;
			nxt[mf][p] = j;
		}
	}
}

void Work2()
{
	cnt ++;
	cin >> ch;
	val[cnt] = -1;
	if (ch.size() <= lmt)
	{
		int nt = 1;
		for(int j = 0,l = ch.size(); j < l; j ++)
		{
			int x = ch[j] - 'a';
			if (!t[nt].to[x]) tot ++, t[nt].to[x] = tot;
			nt = t[nt].to[x];
		}
		t[nt].val --;
	} 
	else
	{
		ra[++ mf] = cnt;
		s[mf] = ch;
		int n = ch.size();
		nxt[mf].resize(n);
		nxt[mf][0] = -1;
		for(int p = 1,j = -1; p < n; p ++)
		{
			for(;j != -1 && ch[p] != ch[j + 1]; j = nxt[mf][j]);
			if (ch[p] == ch[j + 1]) ++ j;
			nxt[mf][p] = j;
		}
	}
}

void Work3()
{
	cin >> ch;
	int ans = 0,l = ch.size();
	for(int j = 0; j < l; j ++)
		for(int k = 1,nt = 1; k <= lmt && j + k - 1 < l; k ++)
		{
			int x = ch[j + k - 1] - 'a';
			nt = t[nt].to[x];
			if (!nt) break;
			ans += t[nt].val;
		}
	for(int j = 1; j <= mf; j ++)
	{
		int len = s[j].size();
		for(int k = 0,p = -1; k < l; k ++)
		{
			for(;p != -1 && s[j][p + 1] != ch[k]; p = nxt[j][p]);
			if (s[j][p + 1] == ch[k]) p ++;
			if (p == len - 1) ans += val[ra[j]], p = nxt[j][p];
		}
	}
	cout << ans << endl;
}

int main()
{		
	cin >> m;
	tot = 1;
	while(m --)
	{
		int op;
		cin >> op;
		if (op == 1) Work1();
		if (op == 2) Work2();
		if (op == 3) Work3();
	}
	return 0;
}