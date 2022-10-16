#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	string s;int n,k;cin>>n>>k>>s;
	vector<int> cnt(300);
	for(auto x:s)cnt[x]++;
	int ans=0;
	for(int i='a';i<='z';i++)
		ans+=cnt[i]/2;
	int res=ans/k,p=0;
	if(n-res*k*2>=k)p=1;
	cout<<res*2+p<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}