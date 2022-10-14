#include<bits/stdc++.h>
#define int long long 
using namespace std;
int const N=233333,B=18,INF=0x3f3f3f3f3f3f3f3fll;
int n,q,h[N],d[N],s[N],lg[N],va[N],vb[N],mx[B][N],mn[B][N];
int tmax(int x,int y){
	return va[x]>va[y]?x:y;
}
int tmin(int x,int y){
	return vb[x]<vb[y]?x:y;
}
int askmax(int l,int r){
	if(l>r)return 0;
	int k=lg[r-l+1];
	return tmax(mx[k][l],mx[k][r-(1<<k)+1]);
}
int askmin(int l,int r){
	if(l>r)return 0;
	int k=lg[r-l+1];
	return tmin(mn[k][l],mn[k][r-(1<<k)+1]);
}
int solve(int l,int r){
	swap(l,r),l++,r--;
	if(l>r)r+=n/2;
	int p1=askmax(l,r),p2=askmin(l,r);
	if(p1!=p2)
		return va[p1]-vb[p2];
	int t1=tmax(askmax(l,p1-1),askmax(p1+1,r)),
		t2=tmin(askmin(l,p1-1),askmin(p1+1,r));
	return max(va[t1]-vb[p2],va[p1]-vb[t2]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>q;
	for(int i=2;i<=n+1;i++)
		cin>>d[i],d[i+n]=d[i];
	d[1]=d[n+1];
	for(int i=1;i<=n;i++)
		cin>>h[i],h[i+n]=h[i];
	n*=2,va[0]=-INF,vb[0]=INF; 
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+d[i],lg[i]=i>1?lg[i>>1]+1:0,
		va[i]=s[i]+2*h[i],vb[i]=s[i]-2*h[i],mn[0][i]=mx[0][i]=i;
	for(int i=1;i<B;i++)
		for(int j=1;j<=n-(1<<i);j++)
			mx[i][j]=tmax(mx[i-1][j],mx[i-1][j+(1<<(i-1))]),
			mn[i][j]=tmin(mn[i-1][j],mn[i-1][j+(1<<(i-1))]);
	while(q--){
		int l,r;cin>>l>>r;
		cout<<solve(l,r)<<"\n"; 
	}
}