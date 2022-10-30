// 
//  
// 
//  
//   
#pragma GCC optimize(2)
#pragma GCC target("avx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
struct comp
{
	double x,y;
	inline comp operator+(comp b) const {return(comp){x+b.x,y+b.y};}
	inline comp operator-(comp b) const {return(comp){x-b.x,y-b.y};}
	inline comp operator*(double b) const {return(comp){x*b,y*b};}
	inline comp operator/(double b) const {return(comp){x/b,y/b};}
	inline comp operator*(comp b) const {return(comp){x*b.x-y*b.y,x*b.y+y*b.x};}
}a[800005],b[800005];
struct node{vector<int>v;bool operator<(node b) const {return v.size()>b.v.size();}};
int n,m,k,c[800005],r[800005];priority_queue<node>q;
inline void FFT(int n,comp *a,int fla)
{
	for(int i=0;i<n;i++) if(i<r[i]) swap(a[i],a[r[i]]);
	for(int d=1;d<n;d<<=1)
	{
		comp wn=(comp){cos(pi/d),fla*sin(pi/d)},w;
		for(int i=0,k;i<n;i+=(d<<1))
			for(k=0,w=(comp){1,0};k<d;k++,w=w*wn)
				{comp x=a[i+k],y=w*a[i+k+d];a[i+k]=x+y,a[i+k+d]=x-y;}
	}
	if(fla==-1) for(int i=0;i<n;i++) a[i]=a[i]/n;
}
inline node times(node A,node B)
{
	int n=A.v.size(),m=B.v.size(),T;
	for(T=1,r[0]=0;T<=n+m;) T<<=1;
	for(int i=0;i<T;i++) r[i]=((r[i>>1]>>1)|((i&1)?(T>>1):0));
	for(int i=0;i<T;i++) a[i]=b[i]=(comp){0,0};
	for(int i=0;i<n;i++) a[i].x=A.v[i];
	for(int i=0;i<m;i++) b[i].x=B.v[i];
	FFT(T,a,1),FFT(T,b,1);
	for(int i=0;i<T;i++) a[i]=a[i]*b[i];
	FFT(T,a,-1);node t;t.v.clear(),t.v.resize(n+m-1);
	for(int i=0;i<=n+m-2;i++) t.v[i]=(long long)(a[i].x+0.5)%1009;
	return t;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);node t;t.v.clear(),t.v.push_back(1);
	for(int i=1,x;i<=n;i++) scanf("%d",&x),c[x]++,c[x]=min(c[x],k+1);
	sort(c+1,c+n+1);
	for(int i=1;i<=n;i++) {while((int)t.v.size()-1<c[i]) t.v.push_back(1);q.push(t);}
	while((int)q.size()>1) {node a=q.top();q.pop();node b=q.top();q.pop();q.push(times(a,b));}
	return printf("%d\n",q.top().v[k]),0;
}