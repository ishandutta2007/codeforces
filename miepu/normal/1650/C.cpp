#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,m;cin>>n>>m;
	vector<vector<int>> w;
	for(int i=1;i<=m;i++){
		int x,a;
		cin>>x>>a;
		w.push_back({a,x,i});
	}
	sort(w.begin(),w.end());
	int res=0;
	for(int i=0;i<n*2;i++)
		res+=w[i][0];
	cout<<res<<endl;
	sort(w.begin(),w.begin()+2*n,[](vector<int>a,vector<int>b){return a[1]<b[1];});
	for(int i=0;i<n;i++){
		cout<<w[i][2]<<' '<<w[2*n-i-1][2]<<endl;
	}
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}