#include<bits/stdc++.h>
#define int long long
const int N=1005000;
using namespace std;

int n,a[N];
int nxt[N<<1];

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	n=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=n;i++)
		nxt[a[i]-1]=i;
	nxt[2*N-1]=n+1;
	for(int i=N*2-1;i;i--)
		if(!nxt[i])nxt[i]=nxt[i+1];
	for(int i=1;i<=a[n]+5;i++){
		int L=i*i,R=i*i+i;
		if(R<a[1])continue;
		int l=max(0ll,L-a[1]),r=R-a[1];
		int nl=l,nr=r;
		int cnt=0;
		for(int j=2;j<=n;){
			int k=ceil((-1+sqrt(1+4*a[j]+4*l))/2);
			int nowR=k*k+k-l;
			int nx=nowR<N*2?nxt[nowR]:n+1;
			if(nx==j){
				j=nx;
			}
			nl=max(nl,k*k-a[j]);
			nr=min(nr,k*k+k-a[nx-1]);
			j=nx;
		}
		if(nl<=nr)cout<<nl<<endl,exit(0);
	}
}
main(){
	ios::sync_with_stdio(0);
	solve();
}