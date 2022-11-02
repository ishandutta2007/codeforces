#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=1<<17;
ll st1[2*N];
ll st2[2*N];

void qrm(int i, int l, int r, int stl, int str, ll mod){
	if (l>str||stl>r) return;
	if (st2[i]<mod) return;
	if (stl==str){
		st1[i]%=mod;
		st2[i]%=mod;
	}
	else{
		int m=(stl+str)/2;
		qrm(i*2, l, r, stl, m, mod);
		qrm(i*2+1, l, r, m+1, str, mod);
		st1[i]=st1[i*2]+st1[i*2+1];
		st2[i]=max(st2[i*2], st2[i*2+1]);
	}
}

ll sum(int i, int l, int r, int stl, int str){
	if (l>str||stl>r) return 0;
	if (l<=stl&&str<=r){
		return st1[i];
	}
	else{
		int m=(stl+str)/2;
		return sum(i*2, l, r, stl, m)+sum(i*2+1, l, r, m+1, str);
	}
}

void qrs(int i, int x, int stl, int str, ll v){
	if (x<stl||x>str) return;
	if (stl==str){
		st1[i]=v;
		st2[i]=v;
	}
	else{
		int m=(stl+str)/2;
		qrs(i*2, x, stl, m, v);
		qrs(i*2+1, x, m+1, str, v);
		st1[i]=st1[i*2]+st1[i*2+1];
		st2[i]=max(st2[i*2], st2[i*2+1]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<n;i++){
		ll a;
		cin>>a;
		st1[i+N]=a;
		st2[i+N]=a;
	}
	for (int i=N-1;i;i--){
		st1[i]=st1[i*2]+st1[i*2+1];
		st2[i]=max(st2[i*2], st2[i*2+1]);
	}
	for (int qq=0;qq<m;qq++){
		int t;
		cin>>t;
		if (t==1){
			int l,r;
			cin>>l>>r;
			l--;
			r--;
			cout<<sum(1, l, r, 0, N-1)<<'\n';
		}
		if (t==2){
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			r--;
			qrm(1, l, r, 0, N-1, x);
		}
		if (t==3){
			int k,x;
			cin>>k>>x;
			k--;
			qrs(1, k, 0, N-1, x);
		}
	}
}