#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;string s;cin>>n;
	vector<int> a(n),b(n),ans(n+1);int c=0;for(auto&x:a)cin>>x,b[x-1]=++c;
	cin>>s;
	vector<int>X,Y; 
	for(int i=0;i<n;i++){
		if(s[i]=='0')X.push_back(a[i]);else Y.push_back(a[i]);
	}
	sort(X.begin(),X.end());
	sort(Y.begin(),Y.end());
//	int ans=0;
	for(int i=0;i<X.size();i++){
		ans[b[X[i]-1]]=i+1;
	}
	for(int i=0;i<Y.size();i++){
		ans[b[Y[i]-1]]=i+1+X.size();
	}
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<' ';cout<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}