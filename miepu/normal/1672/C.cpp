#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;
	cin>>n;
	int fs=n,ed=0;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		if(a[i]==a[i-1])
			fs=min(fs,i),ed=max(ed,i);
	if(ed==0||fs==ed){
		cout<<0<<endl; 
	}else{
		cout<<max(1ll,ed-fs-1)<<endl;
	}
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}