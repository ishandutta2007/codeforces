#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	int c1=0,c0=0,s=0;
	for(int i=0;i<n;i++)cin>>a[i],c1+=a[i];
	int res=n;
	for(int i=n-1;i>=0;i--){
		if(a[i]==1)c1--,c0+=s,s=0;
		else s++;
		if(c0<=c1)res=min(res,c1);		
	} 
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}