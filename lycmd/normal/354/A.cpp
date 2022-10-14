#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int n,l,r,ql,qr,ans=LLONG_MAX,a[N],s[N];
int sum(int l,int r){
	return l>r?0:s[r]-s[l-1];
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>l>>r>>ql>>qr;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];
	for(int i=0;i<=n;i++){
		int t=sum(1,i)*l+sum(i+1,n)*r,cl=i,cr=n-i;
		if(abs(cl-cr)>1){
			if(cl>cr)
				t+=ql*(cl-cr-1);
			else
				t+=qr*(cr-cl-1);
		}
		ans=min(ans,t);
	}
	cout<<ans<<"\n";
}