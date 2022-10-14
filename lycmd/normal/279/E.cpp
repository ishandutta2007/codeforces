#include<bits/stdc++.h>
using namespace std;
int const N=1000010;
int n,f[N][2];
string s;
int main(){
	ios::sync_with_stdio(0);
	cin>>s,n=s.size(),f[0][0]=s[0]&1,f[0][1]=1;
	for(int i=1;i<n;i++){
		int t=s[i]&1;
		f[i][t]=f[i-1][t],f[i][!t]=min(f[i-1][0],f[i-1][1])+1;
	}
	cout<<f[n-1][0]<<"\n";
}