#include<bits/stdc++.h>
using namespace std;
int const N=800010,B=19;
int n,a[N],s[B][N],f[N],lg[N];
int gcd(int x,int y){
	return y?gcd(y,x%y):x;
}
void init(){
	for(int i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)
		s[0][i]=a[i];
	for(int i=1;i<B;i++)
		for(int j=1;j<=n-(1<<(i-1));j++)
			s[i][j]=gcd(s[i-1][j],s[i-1][j+(1<<(i-1))]);
}
int ask(int l,int r){
	int k=lg[r-l+1];
	return gcd(s[k][l],s[k][r-(1<<k)+1]);
}
int check(int x,int k){
	return ask(x,k)<k-x+1;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	init(),f[1]=a[1]==1;
	for(int i=2;i<=n;i++){
		int l=0,r=i;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(check(mid,i))l=mid;else r=mid;
		}
		f[i]=ask(r,i)==i-r+1?max(f[i],f[r-1]+1):f[i-1];
	}
	for(int i=1;i<=n;i++)
		cout<<f[i]<<" ";
	cout<<"\n";
}