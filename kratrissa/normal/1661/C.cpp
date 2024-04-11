#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5;
int T,n,h[N];ll ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",&h[i]);
		int mx=*max_element(h+1,h+n+1);ll cnt=0,w=0,sum=0;
		for(int i=1;i<=n;i++)cnt+=mx-h[i]>>1,w+=mx-h[i]&1,sum+=mx-h[i];
		if(cnt>=w)ans=sum/3*2+(sum%3!=0)+(sum%3==2);
		else ans=2*w-1;
		mx++,cnt=w=sum=0;
		for(int i=1;i<=n;i++)cnt+=mx-h[i]>>1,w+=mx-h[i]&1,sum+=mx-h[i];
		if(cnt>=w)ans=min(ans,sum/3*2+(sum%3!=0)+(sum%3==2));
		else ans=min(ans,2*w-1);
		printf("%lld\n",ans);
	}
	return 0;
}