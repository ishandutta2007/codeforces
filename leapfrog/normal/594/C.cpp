//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=100005,M=15;int cnt=0,vs[N];ll rs=1e18;
int n,K,d1[M],d2[M],d3[M],d4[M];struct node{int x,y,id;}a[N];
int main()
{
	read(n,K);for(int i=1,c,d,e,f;i<=n;i++) read(c,d,e,f),a[i]=(node){c+e,d+f,i};
	//for(int i=1;i<=n;i++) printf("%d %d\n",a[i].x,a[i].y);
	sort(a+1,a+n+1,[](node a,node b){return a.x<b.x;});
	for(int i=1;i<=K+1;i++) d1[i]=a[i].id,d2[i]=a[n-i+1].id;
	sort(a+1,a+n+1,[](node a,node b){return a.y<b.y;});
	for(int i=1;i<=K+1;i++) d3[i]=a[i].id,d4[i]=a[n-i+1].id;
	sort(a+1,a+n+1,[](node a,node b){return a.id<b.id;});
	for(int i=0;i<=K;i++) for(int j=0;j<=K;j++) for(int k=0;k<=K;k++)
	{
		for(int z=1;z<=i;z++) cnt+=!vs[d1[z]]++;
		for(int z=1;z<=j;z++) cnt+=!vs[d2[z]]++;
		for(int z=1;z<=k;z++) cnt+=!vs[d3[z]]++;
		int l=0;while(cnt<=K&&l<=K) cnt+=!vs[d4[++l]]++;
		if(cnt>K&&l) cnt-=!--vs[d4[l--]];
		for(int z=1;z<=i;z++) vs[d1[z]]=0;
		for(int z=1;z<=j;z++) vs[d2[z]]=0;
		for(int z=1;z<=k;z++) vs[d3[z]]=0;
		for(int z=1;z<=l;z++) vs[d4[z]]=0;
		if(cnt>K) {cnt=0;continue;}else cnt=0;
		//printf("%d %d %d %d\n",i,j,k,l);
		//printf("? %d %d %d %d\n",d2[j+1],d1[i+1],d3[l+1],d3[k+1]);
		//printf("? %d %d %d %d\n",a[d1[i+1]].x,a[d2[j+1]].x,a[d3[k+1]].y,a[d4[l+1]].y);
		int x1=max(a[d2[j+1]].x-a[d1[i+1]].x,1);x1++,x1/=2;
		int y1=max(a[d4[l+1]].y-a[d3[k+1]].y,1);y1++,y1/=2;
		rs=min(rs,1ll*x1*y1);
	}
	return printf("%lld\n",rs),0;
}