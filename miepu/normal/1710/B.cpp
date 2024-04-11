#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,m,x[N],p[N];

void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>x[i]>>p[i];
	map<int,int> K;
	for(int i=0;i<n;i++)
		K[x[i]]-=2,K[x[i]-p[i]]++,K[x[i]+p[i]]++;
	int xs=0,pr=K.begin()->first,ns=0;
	int lim1=-1e18,lim2=lim1;
	for(auto i:K){
		ns+=xs*(i.first-pr);
		xs+=i.second,pr=i.first;
		if(ns>m){
			lim1=max(lim1,ns-m+pr);
			lim2=max(lim2,ns-m-pr);
		}
	}
	for(int i=0;i<n;i++)
		cout<<(p[i]+x[i]>=lim1&&p[i]-x[i]>=lim2);
	cout<<'\n';
}

main(){
	ios::sync_with_stdio(0);
	int T;cin>>T;
	while(T--)solve();
}