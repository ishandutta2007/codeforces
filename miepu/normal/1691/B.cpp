#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	map<int,vector<int>> A;
	int n;cin>>n;
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		A[x].push_back(i); 
	} 
	for(auto x:A){
		if(x.second.size()==1){
			cout<<"-1"<<endl;
			return ;
		}
	}
	vector<int> res(n+1);
	for(auto x:A){
		int s=x.second.size();
		for(int i=0;i<s;i++){
			res[x.second[i]]=x.second[(i+1)%s];
		}
	}
	for(int i=1;i<=n;i++)
		cout<<res[i]<<' ';cout<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}