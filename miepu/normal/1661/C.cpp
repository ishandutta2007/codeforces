#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,a[N];
int res=1e18;

void chk(int x){
	int j=0,o=0;
	for(int i=0;i<n;i++){
		int nw=x-a[i];
		j+=nw&1;
		o+=nw>>1;
	}
	int d=(o-j)/3-1;
	d=max(d,0ll);
	if(d>=0)j+=d*2,o-=d;
	res=min(res,max(j*2-1,o*2));
	if(o>=0)j+=2,o--;
	res=min(res,max(j*2-1,o*2));
	if(o>=0)j+=2,o--;
	res=min(res,max(j*2-1,o*2));
}

void solve(){
	cin>>n;
	int x=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		x=max(x,a[i]);
	}
	res=1e18;
	chk(x),chk(x+1);
	cout<<res<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}