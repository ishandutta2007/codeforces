#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;
	cin>>n
;vector<int> a(n),b(n);
for(int i=0;i<n;i++)cin>>a[i];
for(int i=0;i<n;i++)cin>>b[i];
int res=0;
for(int i=1;i<n;i++){
	res+=min(abs(a[i]-a[i-1])+abs(b[i]-b[i-1]),
		abs(a[i]-b[i-1])+abs(b[i]-a[i-1]));
}
cout<<res<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}