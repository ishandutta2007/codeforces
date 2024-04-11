#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n;cin>>n;
	map<int,int> a;
	while(n--){
		int x;cin>>x;
		a[x]++;
	}
	int s=0;
	for(auto x:a)s+=min(x.second,2ll);
	cout<<(s+1)/2<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}