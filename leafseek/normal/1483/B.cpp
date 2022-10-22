#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
const int MaxN=1000000+5,MaxQ=1000000+5,MaxVt=3000000+5,DownBorder=11000000,HighBorder=19000000,Null=0;
const int Inf=(1<<30)-1;
inline int pickrand(const register int beg,const register int end)
	{return abs(rand()*RAND_MAX+rand())%(end-beg+1)+beg;}
struct Vertex
{
	int val;
	int pri;
	int siz;
	int ch[2];
};
Vertex Empty,vt[MaxN];
int OVERALLTot;
inline void push_up(const register int idx)
	{vt[idx].siz=(vt[vt[idx].ch[0]].siz+vt[vt[idx].ch[1]].siz)+1;}
inline int CreateVertex(const register int val)
{
	++OVERALLTot;
	vt[OVERALLTot].val=val;
	vt[OVERALLTot].pri=pickrand(DownBorder,HighBorder);
	vt[OVERALLTot].siz=1;
	vt[OVERALLTot].ch[0]=vt[OVERALLTot].ch[1]=Null;
	return OVERALLTot;
}
inline int Merge(const register int tx,const register int ty)
{
	if(tx==Null) return ty;
	if(ty==Null) return tx;
	if(vt[tx].pri<=vt[ty].pri)
		{vt[tx].ch[1]=Merge(vt[tx].ch[1],ty),push_up(tx);return tx;}
	else
		{vt[ty].ch[0]=Merge(tx,vt[ty].ch[0]),push_up(ty);return ty;}
}
inline void Split(const register int idx,const register int val,register int& tx,register int& ty)
{
	if(idx==Null){tx=ty=Null;return;}
	if(vt[idx].val<=val)
		tx=idx,Split(vt[idx].ch[1],val,vt[idx].ch[1],ty);
	else
		ty=idx,Split(vt[idx].ch[0],val,tx,vt[idx].ch[0]);
	push_up(idx);
}
inline int GetKthVertex(const register int idx,const register int rank)
{
	if(rank<=vt[vt[idx].ch[0]].siz)
		return GetKthVertex(vt[idx].ch[0],rank);
	else if(rank==vt[vt[idx].ch[0]].siz+1)
		return idx;
	else //if(rank>=vt[vt[idx].ch[0]].siz+2)
		return GetKthVertex(vt[idx].ch[1],rank-(vt[vt[idx].ch[0]].siz+1));
}
inline void Insert(register int& Root,const register int val)
{
	register int tx,ty,tz;
	Split(Root,val,tx,ty);
	Root=Merge(Merge(tx,CreateVertex(val)),ty);
}
inline void Delete(register int& Root,const register int val)
{
	register int tx,ty,tz;
	Split(Root,val,tx,ty);
	Split(tx,val-1,tx,tz);
	Root=Merge(Merge(tx,tz=Merge(vt[tz].ch[0],vt[tz].ch[1])),ty);
}
inline int GetRanking(register int& Root,const register int val)
{
	register int tx,ty,tz,Rec;
	Split(Root,val-1,tx,ty);
	Rec=(vt[tx].siz+1),Root=Merge(tx,ty);
	return Rec;
}
inline int GetKthNumber(register int& Root,const register int rank)
	{return vt[GetKthVertex(Root,rank)].val;}
inline int Precursor(register int& Root,const register int val)
{
	register int tx,ty,tz,Rec;
	Split(Root,val-1,tx,ty);
	Rec=(vt[GetKthVertex(tx,vt[tx].siz)].val),Root=Merge(tx,ty);
	return Rec;
}
inline int Successor(register int& Root,const register int val)
{
	register int tx,ty,tz,Rec;
	Split(Root,val,tx,ty);
	Rec=(vt[GetKthVertex(ty,1)].val),Root=Merge(tx,ty);
	return Rec;
}
int arr[MaxN],Prev[MaxN],Next[MaxN];
inline int GetGcd(const register int a,const register int b)
{
	return (b==0)?a:GetGcd(b,a%b);
}
int que[MaxN];
signed main()
{
	register int T;
	scanf("%d",&T);
	register int n;
	while(T--)
	{
		vt[OVERALLTot=0]=Empty;
		register int TreapRoot=0;
		scanf("%d",&n);
		rep(i,1,n)
			scanf("%d",&arr[i]);
		rep(i,1,n)
			Next[i]=i+1;
		Next[n]=1;
		rep(i,1,n)
			Prev[i]=i-1;
		Prev[1]=n;
		rep(i,1,n)
			if(GetGcd(arr[i],arr[Next[i]])==1)
				Insert(TreapRoot,i);
		Insert(TreapRoot,+Inf);
		Insert(TreapRoot,-Inf);
		register int pit=1;
		register int m=0;
		while(true)
		{
			pit=Successor(TreapRoot,pit-1);
			if(pit==+Inf)
			{
				pit=1;
				pit=Successor(TreapRoot,pit-1);
				if(pit==+Inf)
					break;
			}
			register int prev=pit,cur=Next[pit],next=Next[cur];
			Prev[next]=prev,Next[prev]=next,arr[cur]=0,que[++m]=cur;
			if(Successor(TreapRoot,prev-1)==prev)
				Delete(TreapRoot,prev);
			if(Successor(TreapRoot,cur-1)==cur)
				Delete(TreapRoot,cur);
			if(GetGcd(arr[prev],arr[next])==1)
				Insert(TreapRoot,prev);
			pit=next;
		}
		printf("%d ",m);
		rep(i,1,m)
			printf("%d ",que[i]);
		printf("\n");
	}
	return 0;
}