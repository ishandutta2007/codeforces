#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,k,a[N],b[N];
int check(int x){
	for(int i=1;i<=k;i++)
		b[i]=0;
	for(int i=1;i<=n;i++)
		b[a[i]]++;
	int w=0;
	for(int i=1;i<=k;i++)
		if(b[i]>x)w+=b[i]-x;
		else w-=(x-b[i])/2;
	return w<=0;
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>k>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int l=-1,r=5e5;
		while(l<r-1){
			int mid=(l+r)>>1;
			if(check(mid))r=mid;else l=mid;
		}
		cout<<r<<"\n";
	}
}