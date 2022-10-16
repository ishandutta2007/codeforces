#include<bits/stdc++.h>
#define int long long
const int N=1000050,P=18;
using namespace std;

void solve(){
	int l,r;cin>>l>>r;
	int n=r-l+1;
	vector<int> a(n);
	vector<int> cnt1(P),cnt2(P);
	for(auto x:a){
		cin>>x;
		for(int j=0;j<P;j++)
			if(x>>j&1)
				cnt2[j]++;
	}
	for(int i=l;i<=r;i++){
		for(int j=0;j<P;j++)
			if(i>>j&1)
				cnt1[j]++;
	}
	int res=0;
	for(int i=0;i<P;i++)
		if(cnt1[i]!=cnt2[i])
			res|=1<<i;
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}