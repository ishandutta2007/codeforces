#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
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
struct trie
{
	int ch[26];
	int fail;
	int tail;
}t[1000010];
int g(char c)
{
	return c-'a';
}
int insert(string s)
{
	int l=s.size();
	int nw=0;
	up(i,0,l-1)
	{
		if(t[nw].ch[g(s[i])]==0)
		{
			t[nw].ch[g(s[i])]=++cnt;
		}
		nw=t[nw].ch[g(s[i])];
		
	}
	return nw;
}
vector<int>v[1010010];
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
		v[t[nw].fail].push_back(nw);
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

int l[1010100],r[1010010],tot=-1;
void dfs(int x)
{
	l[x]=++tot;
	for(auto i:v[x]){dfs(i);}
	r[x]=tot;
}
int id[1010010];
int f[1010010];
void clr()
{
	memset(f,0,sizeof(f));
}
int lowbit(int x)
{
	return x&(-x);
}
void upd(int x,int y)
{
	if(!x)return;
	for(int i=x;i<=tot;i+=lowbit(i))f[i]+=y;
}
int qry(int x)
{
	int ans=0;
	for(int i=x;i>=1;i-=lowbit(i))ans+=f[i];
	return ans;
}
int b[101010];
signed main()
{
	n=read(),k=read();
	up(i,1,k)
	{
		string s;
		cin>>s;
		id[i]=insert(s);
	}
	bfs();
	dfs(0);
	up(i,1,k)
	{
		upd(l[id[i]],1);
		upd(r[id[i]]+1,-1);
		b[i]++;
	}
	up(i,1,n)
	{
		string s;
		cin>>s;
		if(s[0]=='?')
		{
			int ans=0;
			int pw=0;
			up(j,1,s.size()-1)
			{
				int nw=s[j]-'a';
				pw=t[pw].ch[nw];
				ans+=qry(l[pw]);
			}
			cout<<ans<<endl;
		}
		else
		{
			string ss=s.substr(1);
			int nw=stoi(ss);
			if(s[0]=='-')
			{
				if(!b[nw])continue;
				b[nw]--;
				upd(l[id[nw]],-1);
				upd(r[id[nw]]+1,1);
			}
			else
			{
				if(b[nw])continue;
				b[nw]++;
				upd(l[id[nw]],1);
				upd(r[id[nw]]+1,-1);
			}
		}
	}
}