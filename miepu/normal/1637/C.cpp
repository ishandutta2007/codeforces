#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;
	vector<int> a(n);
	int fl=0,sum=0,f2=0;
	for(auto&x:a)cin>>x;
	if(n==3&&(a[1]&1))cout<<-1<<endl;
	else{
		for(int i=1;i<n-1;i++)fl+=a[i]>1,f2+=a[i]&1,sum+=(a[i]+1)/2;
		if(f2&&!fl)cout<<-1<<endl;
		else cout<<sum<<endl; 
	}
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}