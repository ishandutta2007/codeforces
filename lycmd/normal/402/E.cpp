#include<bits/stdc++.h>
using namespace std;
int const N=2010;
int n,x;
bitset<N>f[N];
int main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>x,f[i][j]=x>0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(f[j][i])
				f[j]|=f[i];
	int flg=1;
	for(int i=1;i<=n;i++)
		flg&=f[i].count()==n;
	cout<<(flg?"YES\n":"NO\n");
}