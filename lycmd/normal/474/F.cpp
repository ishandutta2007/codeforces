#include<bits/stdc++.h>
using namespace std;
int const N=100010,B=18;
int n,q,a[N],c[N],lg[N],mn[B][N],g[B][N];
vector<int>b,p[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void init(){
	for(int i=1;i<=n;i++)
		mn[0][i]=g[0][i]=a[i],lg[i]=i>1?lg[i>>1]+1:0; 
	for(int i=1;i<B;i++)
		for(int j=1;j<=n-(1<<(i-1));j++)
			mn[i][j]=min(mn[i-1][j],mn[i-1][j+(1<<(i-1))]),
			g[i][j]=gcd(g[i-1][j],g[i-1][j+(1<<(i-1))]);
}
int askgcd(int l,int r){
	int k=lg[r-l+1];
	return gcd(g[k][l],g[k][r-(1<<k)+1]);
}
int askmin(int l,int r){
	int k=lg[r-l+1];
	return min(mn[k][l],mn[k][r-(1<<k)+1]); 
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],b.push_back(a[i]);
	sort(b.begin(),b.end());
	for(int i=1;i<=n;i++)
		c[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1,
		p[c[i]].push_back(i);
	init();
	for(cin>>q;q--;){
		int l,r;cin>>l>>r;
		int t1=askmin(l,r),t2=askgcd(l,r);
		if(t1^t2){
			cout<<r-l+1<<"\n";
			continue;
		}
		int k=lower_bound(b.begin(),b.end(),t1)-b.begin()+1,
			pl=lower_bound(p[k].begin(),p[k].end(),l)-p[k].begin(),
			pr=upper_bound(p[k].begin(),p[k].end(),r)-p[k].begin()-1;
		cout<<r-l-pr+pl<<"\n";
	} 
}