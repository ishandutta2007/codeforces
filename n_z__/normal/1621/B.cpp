#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int power(int a,int b){
	int ans=1,now=a;
	while(b){
		if(b&1){
			ans*=now;
			ans%-mod;
		}
		now*=now;
		now%=mod;
		b>>=1;
	}
	return ans;
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int l[n+1],r[n+1],c[n+1],minv,maxv;
		for(int i=1;i<=n;i++){
			cin>>l[i]>>r[i]>>c[i];
		}
		minv=l[1],maxv=r[1];
		cout<<c[1]<<endl;
		int minx=c[1],maxx=c[1],thr=c[1];
		for(int i=2;i<=n;i++){
			if(l[i]<minv){
				thr=1e17;
				minx=c[i],minv=l[i];
			}
			if(r[i]>maxv){
				thr=1e17;
				maxx=c[i],maxv=r[i];
			}
			if(l[i]==minv){
				minx=min(minx,c[i]);
			}
			if(r[i]==maxv){
				maxx=min(maxx,c[i]);
			}
			if(l[i]==minv&&r[i]==maxv){
				thr=min(thr,c[i]);
			}
			cout<<min(maxx+minx,thr)<<endl;
		}
	} 
}