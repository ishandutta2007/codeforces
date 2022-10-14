#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,n--;
	for(int i=1;n;n>>=1,i<<=1)
		ans+=(n+1)/2*i;
	cout<<ans<<"\n";
}