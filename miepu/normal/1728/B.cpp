#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	for(int i=0;i<n-2;i++){
		a[i]=n-2-i;
	}
	a[n-2]=n-1;
	a[n-1]=n;
	if(n&1)swap(a[0],a[1]);
	for(auto x:a)cout<<x<<' ';cout<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}