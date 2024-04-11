#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,s,n,k;
signed main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--)
		cin>>s>>n>>k,
		cout<<(s==k||s>k&&s/2/k*k+min(k,s%(k*2))-s/k%2<n?"YES\n":"NO\n");
}