#include<bits/stdc++.h>
#define int long long
const int N=200005;
using namespace std;

multiset<int> S[N]; 
int n,a[N];
int q;
vector<int> sm[N];
vector<int> d;

void query(){
	int mx=0;
	for(int i=0;i<d.size();i++){
		mx=max(mx,*S[i].rbegin()*(n/d[i]));
	}
	cout<<mx<<'\n';
}

void solve(){
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>a[i];
	d.clear();
	for(int i=2;i<=n;i++){
		if(n%i==0){
			int flag=1;
			for(auto x:d){
				if(i%x==0)
					flag=0;
			}
			if(!flag)continue;
			d.push_back(i);
		}
	}
	int sz=d.size();
	for(int i=0;i<sz;i++){
		int x=n/d[i];
		S[i].clear();
		sm[i].clear(); 
		sm[i].resize(x);
		for(int j=0;j<n;j++){
			sm[i][j%x]+=a[j];
		}
		for(int j=0;j<x;j++)S[i].insert(sm[i][j]); 
	}
	query();
	for(int i=0;i<q;i++){
		int x,y;cin>>x>>y;x--;
		int del=y-a[x];
		a[x]=y;
		for(int i=0;i<sz;i++){
			int p=n/d[i];
			S[i].erase(S[i].find(sm[i][x%p]));
			sm[i][x%p]+=del;
			S[i].insert(sm[i][x%p]);
		}
		query();
	}
}

main(){
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}