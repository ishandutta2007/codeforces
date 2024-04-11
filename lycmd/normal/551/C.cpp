#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010;
int n,m,a[N],b[N];
int check(int x){
	int p=n,tm=m;
	for(memcpy(b,a,sizeof b);p&&tm--;){
		while(p&&!b[p])
			p--;
		for(int k=x-p;p&&k>0;){
			int t=min(k,b[p]);
			k-=t,b[p]-=t;
			while(p&&!b[p])
				p--;
		}
	}
	return!p;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int l=-1,r=1e15;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;else l=mid;
	}
	cout<<r<<"\n";
}