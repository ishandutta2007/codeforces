#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=100000+5,MaxM=200000+5,MaxQ=200000+5,MaxLoad=400000+5;
constexpr int MaxTr=200000+5,Sigma=26,Error=(-1),Limit=(1<<18);
inline int Char_Index(const char x)
	{return (x?(x-'a'):(-1));}
struct Tree_Node
{
	int len,link;
	bool Flag;
	int Inn,Out;
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
inline void SAM_Insert(int &Last,const int x)
{
	const int Cur=New_Node();
	tr[Cur].len=(tr[Last].len+1),tr[Cur].Flag=true;
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
		tr[z]=tr[v],tr[z].len=(tr[u].len+1),tr[z].Flag=false;
		while((u!=Error)&&(tr[u].ch[x]==v))
			tr[u].ch[x]=z,u=tr[u].link;
		tr[v].link=tr[Cur].link=z;
	}
	Last=Cur;
}
struct Zkw_Segment_Tree
{
	int Max[(Limit<<1)|5];
	inline void Modify(const int pos,const int wei)
	{
		int u=(Limit|pos);
		Max[u]=wei;
		while(u>>=1)
			Max[u]=max(Max[u<<1],Max[u<<1|1]);
	}
	inline int Query(const int lef,const int rig)
	{
		int Record=0;
		for(int u=(Limit|(lef-1)),v=(Limit|(rig+1));u^v^1;u>>=1,v>>=1)
		{
			if(~u&1) Record=max(Record,Max[u^1]);
			if( v&1) Record=max(Record,Max[v^1]);
		}
		return Record;
	}
};
Zkw_Segment_Tree St;
struct Offline_Operation
{
	bool cmd;
	int idx;
	int u,lef;
	char *str;
};
vector<Offline_Operation> op[MaxN];
int op_Tot[MaxN],Overall_Inn;
inline void Dfs_Basics(const int u)
{
	int v;
	if(tr[u].Flag)
	{
		tr[u].Inn=tr[u].Out=(++Overall_Inn);
		++op_Tot[tr[u].len],op[tr[u].len].push_back((Offline_Operation){true,0,u,0,nullptr});
	}
	rep(I,1,tr[u].adj[0])
		Dfs_Basics(v=tr[u].adj[I]);
	if(!tr[u].Flag)
		tr[u].Inn=tr[tr[u].adj[1]].Inn;
	if(tr[u].adj[0])
		tr[u].Out=tr[tr[u].adj[tr[u].adj[0]]].Out;
}
int Eps_u[MaxM],Answer_lef[MaxQ],Answer_rig[MaxQ];
char arr[MaxN],str_Load[MaxLoad],*str=str_Load;
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m,q;
	cin>>(arr+1),n=strlen(arr+1);
	int Last=((tr[0].link=Error,tr[0].adj.push_back(0)),0);
	rep(i,1,n)
	{
		SAM_Insert(Last,Char_Index(arr[i]));
		op[i].push_back((Offline_Operation){false,0,0,0,nullptr});
	}
	const int Tot=Overall_Tot;
	int u,v;
	rep(i,1,Tot)
		u=tr[i].link,++tr[u].adj[0],tr[u].adj.push_back(i);
	Dfs_Basics(0),cin>>q;
	int lef,rig;
	rep(i,1,q)
	{
		cin>>lef>>rig>>(str+1),m=strlen(str+1);
		++op_Tot[rig],op[rig].push_back((Offline_Operation){false,i,0,lef,str}),str+=(m+1);
	}
	rep(i,1,n)
		rep(I,1,op_Tot[i])
		{
			if(op[i][I].cmd)
				u=op[i][I].u,St.Modify(tr[u].Inn,tr[u].len);
			else
			{
				lef=op[i][I].lef,rig=i,str=op[i][I].str,m=strlen(str+1),u=0;
				int Epsilon=min(m,rig-lef);
				rep(j,1,min(m,rig-lef))
				{
					const int x=Char_Index(str[j]);
					if(!tr[u].ch[x])
						{Epsilon=(j-1);break;}
					u=tr[u].ch[x],Eps_u[j]=u;
				}
				bool Is_Answer=false;
				dow(j,Epsilon,0)
				{
					u=Eps_u[j];
					const int x=Char_Index(str[j+1]);
					rep(y,x+1,Sigma-1)
					{
						if(!(v=tr[u].ch[y]))
							continue;
						const int Max=St.Query(tr[v].Inn,tr[v].Out);
						if(Max>=(lef+j))
						{
							Is_Answer=true;
							Answer_lef[op[i][I].idx]=(Max-j);
							Answer_rig[op[i][I].idx]=Max;
							break;
						}
					}
					if(Is_Answer) break;
				}
			}
		}
	rep(i,1,q)
	{
		if(!Answer_lef[i])
			{cout<<"-1\n";continue;}
		const char x=arr[Answer_rig[i]+1];
		arr[Answer_rig[i]+1]=0,cout<<(arr+Answer_lef[i])<<'\n';
		arr[Answer_rig[i]+1]=x;
	}
	return 0;
}