#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,k,l1,l2,r1,r2;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>k>>l1>>r1>>l2>>r2;
		if(l1==l2&&r1==r2)
			cout<<max((k-n*r1+n*l1)*2,0ll)<<"\n";
		else if(max(l1,l2)<=min(r1,r2)){
			if(l1>l2)
				swap(l1,l2);
			if(r1>r2)
				swap(r1,r2);
			k-=n*(r1-l2);
			int s=n*(r2-r1-l1+l2);
			if(k<=0)
				cout<<"0\n";
			else if(k<=s)
				cout<<k<<"\n";
			else
				cout<<s+(k-s)*2<<"\n";
		}else{
			if(l1>l2)
				swap(l1,l2),swap(r1,r2);
			int res=LLONG_MAX;
			for(int i=1;i<=n;i++){
				int t=l2-r1,s=r2-l1;
				if(k>s*i)
					res=min(res,(t+s)*i+(k-s*i)*2);
				else
					res=min(res,k/s*(s+t)+(k%s?t+k%s:0));
			}
			cout<<res<<"\n";
		}
	}
}