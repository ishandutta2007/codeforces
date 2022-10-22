#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=1000000+5,MaxM=1000000+5,MaxTr=2000000+5,Sigma=26,Error=(-1);
inline int Char_Index(const char x)
	{return (x-'a');}
struct Tree_Node
{
	int len,link;
	int siz;
	int ch[Sigma];
	vector<int> adj;
};
Tree_Node tr[MaxTr];
int Overall_Tot;
inline int New_Node(void)
{
	const int u=(++Overall_Tot);
	tr[u].adj.push_back(0);
	return u;
}
inline void SAM_Extend(int &Last,const int x)
{
	const int Cur=New_Node();
	tr[Cur].len=(tr[Last].len+1),tr[Cur].siz=1;
	int u=Last;
	while((u!=Error)&&(!tr[u].ch[x]))
		tr[u].ch[x]=Cur,u=tr[u].link;
	if(u==Error)
		{Last=Cur;return;}
	const int v=tr[u].ch[x];
	if((tr[u].len+1)==tr[v].len)
		tr[Cur].link=v;
	else
	{
		const int z=New_Node();
		tr[z]=tr[v],tr[z].len=(tr[u].len+1),tr[z].siz=0;
		while((u!=Error)&&(tr[u].ch[x]==v))
			tr[u].ch[x]=z,u=tr[u].link;
		tr[v].link=tr[Cur].link=z;
	}
	Last=Cur;
}
inline void Dfs_Basics(const int u)
{
	int v;
	rep(I,1,tr[u].adj[0])
	{
		v=tr[u].adj[I],Dfs_Basics(v);
		tr[u].siz+=tr[v].siz;
	}
}
char arr[MaxN],str[MaxM<<1];
int kmp[MaxM];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m_0,m_1,q;
	cin>>(arr+1),n=strlen(arr+1);
	int Last=((tr[0].link=Error,tr[0].adj.push_back(0)),0);
	rep(i,1,n)
		SAM_Extend(Last,Char_Index(arr[i]));
	const int Tot=Overall_Tot;
	rep(i,1,Tot)
		++tr[tr[i].link].adj[0],tr[tr[i].link].adj.push_back(i);
	Dfs_Basics(0),cin>>q;
	while(q--)
	{
		cin>>(str+1),m_1=m_0=strlen(str+1);
		int pos=0;
		rep(i,2,m_0)
		{
			while(pos&&(str[pos+1]!=str[i]))
				pos=kmp[pos];
			kmp[i]=((str[pos+1]==str[i])?(++pos):pos);
		}
		rep(i,((m_0%(m_0-pos))?0:pos)+1,m_0-1)
			str[++m_1]=str[i];
		int u=0,len=0,Answer=0;
		rep(i,1,m_1)
		{
			const int x=Char_Index(str[i]);
			while((u!=Error)&&(!tr[u].ch[x]))
				u=tr[u].link,len=tr[u].len;
			if(u==Error)
				{u=0,len=0;continue;}
			u=tr[u].ch[x],++len;
			if(len==m_0)
			{
				Answer+=tr[u].siz;
				if((--len)==tr[tr[u].link].len)
					u=tr[u].link;
			}
		}
		cout<<Answer<<'\n';
	}
	return 0;
}