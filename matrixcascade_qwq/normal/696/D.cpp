#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define graph(i,x) for(int i=head[x];i;i=nxt[i])
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
int cnt=0;
int v[101010];
struct trie
{
	int ch[30];
	int fail;
	int tail;
}t[1010010];
struct matrix
{
	int mp[222][222];
	matrix()
	{
		memset(mp,0xc0,sizeof(mp));
	}
	matrix operator*(const matrix &x)const
    {
        matrix c;
        up(k,0,cnt)up(i,0,cnt)up(j,0,cnt)c.mp[i][j]=max(c.mp[i][j],mp[i][k]+x.mp[k][j]);
        return c;
    }
}bas;
void insert(string s,int y)
{
	int l=s.size();
	int nw=0;
	up(i,0,l-1)
	{
		if(t[nw].ch[s[i]-'a']==0)
		{
			t[nw].ch[s[i]-'a']=++cnt;
		}
		nw=t[nw].ch[s[i]-'a'];
	}
	t[nw].tail+=y;
}
void bfs()
{
	queue<int>q;
	up(i,0,25)
	{
		if(t[0].ch[i])
		{
			t[t[0].ch[i]].fail=0;
			q.push(t[0].ch[i]);
		}
	}
	while(!q.empty())
	{
		int nw=q.front();
		q.pop();
		t[nw].tail+=t[t[nw].fail].tail;
		up(i,0,25)
		{
			if(t[nw].ch[i]!=0)
			{
				t[t[nw].ch[i]].fail=t[t[nw].fail].ch[i];
				q.push(t[nw].ch[i]);
			}
			else
			{
				t[nw].ch[i]=t[t[nw].fail].ch[i];
			}
		}
	}
}
matrix qpow(matrix a,int b)
{
	matrix c;
	up(i,0,cnt)c.mp[i][i]=0;
	while(b)
	{
		if(b&1)c=c*a;
		a=a*a;
		b>>=1;
	}return c;
}
signed main()
{
	int n=read(),m=read();
	up(i,1,n)v[i]=read();
	up(i,1,n)
	{
		string s;
		cin>>s;
		insert(s,v[i]);
	} 
	t[0].fail=0;
	bfs();
	up(i,0,cnt)
	{
		up(j,0,25)
		{
			int to=t[i].ch[j];
			bas.mp[i][to]=t[to].tail;
		}
	}
	
	bas=qpow(bas,m);
	int mx=0;
	up(i,0,cnt)mx=max(mx,bas.mp[0][i]);cout<<mx;
}