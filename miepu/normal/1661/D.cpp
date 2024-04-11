#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

int n,k,res,b[N],t[N],sm,s;
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=n;i>=1;i--){
		int d=min(k,i);
		b[i]-=sm;
		b[i]=max(b[i],0ll);
		int nw=ceil(1.*b[i]/d);
		t[i]=nw;
		res+=nw;
		sm+=t[i]*d;
		s+=t[i];
		sm-=s;
		s-=t[i+k-1];
	}	
	cout<<res<<endl;
}

main(){
	int _T=1;//cin>>_T;
	while(_T--)solve();
}