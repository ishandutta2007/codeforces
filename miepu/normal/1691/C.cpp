#include<bits/stdc++.h>
#define int long long
const int N=1000050;
using namespace std;

void solve(){
	int n,k;cin>>n>>k;
	string s;cin>>s;
	int res=0,fs=n,ed=-1;
	for(int i=0;i<n;i++){
		auto x=s[i];
		if(x=='1')res+=11,fs=min(fs,i),ed=max(ed,i);
	}
	if(res==0){
		cout<<res<<endl;
		return ;
	}
	int p=n-ed-1,fl=0;
	if(k>=p){
		k-=p;
		fl=1;
		res-=10;
	} 
	if(fs==ed&&fl){
		cout<<res<<endl;
		return ;
	}
	p=fs;
	if(k>=p){
		res--;
	}
	cout<<res<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;cin>>_T;
	while(_T--)solve();
	
}