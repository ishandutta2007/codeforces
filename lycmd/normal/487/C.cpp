#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,inv[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	if(n==4){
		cout<<"YES\n1\n3\n2\n4\n";
	}else{
		for(int i=2;i*i<=n;i++)
			if(n%i==0){
				cout<<"NO\n";
				return 0;
			}
		inv[0]=inv[1]=1;
		for(int i=2;i<=n;i++)
			inv[i]=(n-n/i)*inv[n%i]%n;
		cout<<"YES\n1\n";
		for(int i=2;i<n;i++)
			cout<<inv[i]*(i-1)%n<<"\n";
		if(n>1)cout<<n<<"\n";
	}
}