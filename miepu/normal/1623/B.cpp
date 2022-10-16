#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

void solve(){
	int n;cin>>n;vector<int> l(n),r(n),d(n),v(n+1);
	for(int i=0;i<n;i++){
		cin>>l[i]>>r[i],d[i]=r[i]-l[i]+1;
	}
	for(int i=0;i<n;i++){
		int nw=n,p=n;
		for(int i=0;i<n;i++)
			if(d[i]==1)nw=i;
		cout<<l[nw]<<" "<<r[nw]<<' ';
		for(int i=l[nw];i<=r[nw];i++)
			if(!v[i])v[i]=1,p=i,cout<<i<<endl;
		for(int i=0;i<n;i++)
			if(l[i]<=p&&r[i]>=p)d[i]--;
	}
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}