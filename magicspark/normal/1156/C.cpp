#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,z;
int a[222222];
bool check(int x){
	if(x>n/2)return false;
	int tmp=n-x;
	for(int i=0;i<x;i++){
		int to=tmp+i;
		if(a[to]-a[i]<z)return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>z;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	int l=-1,r=n;
	while(r-l>1){
		int mid=l+r>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	cout<<l<<endl;
	return 0;
}