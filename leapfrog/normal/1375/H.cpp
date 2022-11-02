#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=1<<12|5,B=1<<8,Lim=2.2e6;
int n,q,a[N],wh[N],rsx[Lim],rsy[Lim],rst,rsid[1<<16|5];
inline int mrg(int x,int y) {return !x||!y?x|y:(rsx[++rst]=x,rsy[rst]=y,rst);}
struct block
{
	int id[B+5][B+5],len,pos[B+5];//pos id 
	block(int x=0) {if(x) len=1,id[1][1]=pos[1]=wh[x];}
	inline int qryid(int l,int r)
	{//
		if(r<pos[1]||l>pos[len]) return 0;
		int le=lower_bound(pos+1,pos+len+1,l)-pos;
		int ri=upper_bound(pos+1,pos+len+1,r)-pos-1;
		return le>ri?0:id[le][ri];
	}
	inline block operator+(block y)
	{
		block rs;rs.len=len+y.len;//guard that *this < y
		for(int i=1;i<=len;i++) rs.pos[i]=pos[i];
		for(int i=1;i<=y.len;i++) rs.pos[i+len]=y.pos[i];
		sort(rs.pos+1,rs.pos+rs.len+1);
		for(int i=1;i<=rs.len;i++) for(int j=i;j<=rs.len;j++)
			rs.id[i][j]=mrg(qryid(rs.pos[i],rs.pos[j]),y.qryid(rs.pos[i],rs.pos[j]));
		return rs;
	}
	inline void output()
	{
		puts("-----------------------------------------");
		printf("seg : %d\nthe val : ",len);
		for(int i=1;i<=len;i++) printf("%d%c",pos[i],i==len?'\n':' ');
		for(int i=1;i<=len;i++) for(int j=i;j<=len;j++) printf("%d%c",id[i][j],j==len?'\n':' ');
		puts("-----------------------------------------");
	}
}A[N/B+5];
inline block solve(int l,int r)
{//
	int md=(l+r)>>1;if(l==r) return block(l);
	return solve(l,md)+solve(md+1,r);
}
int main()
{
	read(n,q),rst=n;for(int i=1;i<=n;i++) read(a[i]),wh[a[i]]=i;
	for(int i=0;i<=(n-1)/B;i++) A[i]=solve(i*B+1,min(i*B+B,n));
	//A[0].output();
	for(int k=1,l,r;k<=q;k++)
	{
		read(l,r),rsid[k]=0;
		for(int i=0;i<=(n-1)/B;i++) rsid[k]=mrg(rsid[k],A[i].qryid(l,r));
	}
	printf("%d\n",rst);for(int i=n+1;i<=rst;i++) printf("%d %d\n",rsx[i],rsy[i]);
	for(int i=1;i<=q;i++) printf("%d%c",rsid[i],i==q?'\n':' ');
	return 0;
}