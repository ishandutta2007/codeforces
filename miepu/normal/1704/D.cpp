#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n,m;cin>>n>>m;
	vector<int> res(n);
	for(int i=0;i<n;i++){
		vector<int> a(m);
		for(int j=0;j<m;j++)cin>>a[j],res[i]+=a[j]*j;
	}
	auto px=res;
	sort(px.begin(),px.end());
	int Res=px[n/2];
	for(int i=0;i<n;i++){
		if(res[i]!=Res){
			cout<<i+1<<' '<<abs(res[i]-Res)<<endl;
			return ;
		}
	}
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}