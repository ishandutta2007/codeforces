#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const ll M=3e6;
ll cnt[M+300];
ll cnts[M+300];
ll v[3*M+600];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		cnt[a]++;
	}
	for (int i=M;i>=0;i--){
		cnts[i]=cnts[i+1]+cnt[i];
	}
	for (int i=1;i<=M;i++){
		if (cnt[i]==0) continue;
		int x=M/i+1;
		ll t=cnts[x];
		v[x*i]+=t*cnt[i];
		for (int j=x-1;j>=1;j--){
			v[j*i]+=cnt[j]*cnt[i];
		}
	}
	for (ll i=1;i<=M;i++){
		if (i*i<=3*M) v[i*i]-=cnt[i];
		else {
			v[3*M]-=cnt[i];
		}
	}
	for (int i=3*M;i>=0;i--){
		v[i]=v[i+1]+v[i];
	}
	int m;
	cin>>m;
	for (int i=0;i<m;i++){
		int p;
		cin>>p;
		cout<<v[p]<<"\n";
	}
}