#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int check(int x){
	int cnt=0,t=n;
	for(;t;t-=t/10)cnt+=min(t,x),t-=min(t,x);
	return cnt*2>=n;
}
signed main(){
	cin>>n;
	int l=0,r=n+1;
	while(l<r-1){
		int mid=(l+r)>>1;
		if(check(mid))r=mid;else l=mid;
	}
	cout<<r<<"\n";
}