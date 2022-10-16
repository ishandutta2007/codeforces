#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	vector<int> a(3);for(auto&x:a)cin>>x;
	sort(a.begin(),a.end());
	cout<<(a[0]+a[1]==a[2]||a[0]==a[1]&&a[2]%2==0||a[0]%2==0&&a[1]==a[2]?"Yes":"No")<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}