#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,k;cin>>n>>k;
	vector<int> a(n);map<int,int> cnt;
	int res=0,mx=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		res++;
		cnt[a[i]]=1;
		mx=max(mx,a[i]);
	} 
	int mex=0;
	while(k--){
		while(cnt[mex])mex++;
		if(cnt[(mex+mx+1)/2])break;
		if(mex>mx){
			res+=k+1;
			break;
		}
		cnt[(mex+mx+1)/2]=1;
		res++;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}