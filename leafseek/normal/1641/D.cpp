#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=100000+5,MaxM=5+2,MaxTr=3200000+5,Infinity=((1<<30)|((1<<30)-1));
struct Tree_Node
{
	int Cum;
	map<int,int> ch;
};
Tree_Node tr[MaxTr];
int Overall_Tot;
inline int New_Node(void)
	{return (++Overall_Tot);}
inline void Dfs_Modify(const int u,const int *Arr,const int k,const int I,const bool Flag)
{
	if(I==(k+1))
		{(Flag?(--tr[u].Cum):(++tr[u].Cum));return;}
	Dfs_Modify(u,Arr,k,I+1,Flag);
	int v=tr[u].ch[Arr[I]];
	if(!v) v=tr[u].ch[Arr[I]]=New_Node();
	Dfs_Modify(v,Arr,k,I+1,!Flag);
}
inline int Dfs_Query(const int u,const int *Arr,const int k,const int I)
{
	if(I==(k+1)) return tr[u].Cum;
	const int Record=Dfs_Query(u,Arr,k,I+1);
	if(!tr[u].ch[Arr[I]]) return Record;
	return (Record+Dfs_Query(tr[u].ch[Arr[I]],Arr,k,I+1));
}
int arr[MaxN][MaxM],wei[MaxN],the[MaxN];
struct Compare
	{inline bool operator () (const int p_0,const int p_1)
		{return (wei[p_0]<wei[p_1]);}};
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,k;
	cin>>n>>k;
	const int Trie_Root=New_Node();
	rep(i,1,n)
	{
		rep(I,1,k) cin>>arr[i][I];
		sort(arr[i]+1,arr[i]+k+1);
		Dfs_Modify(Trie_Root,arr[i],k,1,false);
		cin>>wei[i],the[i]=i;
	}
	sort(the+1,the+n+1,Compare());
	int pos=n,Answer=(+Infinity);
	rep(i,1,pos)
	{
		const int u=the[i];
		Dfs_Modify(Trie_Root,arr[u],k,1,true);
		int Count=Dfs_Query(Trie_Root,arr[u],k,1);
		if(!Count) continue;
		while(Count)
		{
			const int v=the[pos];
			bool Flag=false;
			rep(I,1,k)
				if(arr[u][I]==arr[v][lower_bound(arr[v]+1,arr[v]+k+1,arr[u][I])-arr[v]])
					{Flag=true;break;}
			Dfs_Modify(Trie_Root,arr[v],k,1,true),--pos;
			if(!Flag) --Count;
		}
		++pos,Dfs_Modify(Trie_Root,arr[the[pos]],k,1,false);
		Answer=min(Answer,(wei[u]+wei[the[pos]]));
		assert(i<pos);
	}
	cout<<((Answer==(+Infinity))?(-1):Answer)<<'\n';
	return 0;
}