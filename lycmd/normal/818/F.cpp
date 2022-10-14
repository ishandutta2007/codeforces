#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;)
		cin>>n,k=sqrtl(2*n),k+=k*(k+1)<=2*n,
		cout<<n-k-k+max(n,(k*k-k)/2+2)<<"\n";
}