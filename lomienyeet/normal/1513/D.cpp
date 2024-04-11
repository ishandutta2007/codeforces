#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ff first
#define ss second
void solve(){
	int n,p;
	cin>>n>>p;
	pair<int,int> pp[n];
	int wao[n],ok[n]={0};
	for(int i=0;i<n;i++){
		cin>>wao[i];
		pp[i]={wao[i],i};
	}
	sort(pp,pp+n);
	int ans=0,ptr=0;
	while(ptr<n){
		auto e=pp[ptr];
		if(e.ff>=p)break;
		while(e.ss){
			if(ok[e.ss-1]||wao[e.ss-1]%e.ff)break;
			ok[--e.ss]=1226;
			ans+=e.ff;
		}
		e.ss=pp[ptr].ss;
		while(e.ss<n-1){
			if(ok[e.ss]||wao[e.ss+1]%e.ff)break;
			ok[e.ss++]=1226;
			ans+=e.ff;
		}
		ptr++;
	}
	for(int i=0;i<n-1;i++){
		if(!ok[i])ans+=p;
	}
	cout<<ans<<"\n";
}
signed main(){
	int t;
	cin>>t;
	while(t--)solve();
}