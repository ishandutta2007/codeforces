#include<bits/stdc++.h>
using namespace std;
int const N=2333,M=12;
int n,a[N],f[M][N],lg[N];
void build(){
	for(int i=2;i<=n;i++)
		lg[i]=lg[i>>1]+1;
	for(int i=1;i<=n;i++)
		f[0][i]=a[i];
	for(int i=1;i<=11;i++)
		for(int j=1;j<=n-(1<<(i-1))+1;j++)
			f[i][j]=__gcd(f[i-1][j],f[i-1][j+(1<<(i-1))]);
}
int query(int l,int r){
	int k=lg[r-l+1];
	return __gcd(f[k][l],f[k][r-(1<<k)+1]);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	int flg=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],flg+=a[i]==1;
	if(flg)
		cout<<n-flg<<"\n",exit(0);
	build();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			if(query(j,j+i-1)==1)
				cout<<i+n-2<<"\n",exit(0);
	cout<<"-1\n";
}