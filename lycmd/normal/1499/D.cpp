#include<bits/stdc++.h>
using namespace std;
int const N=23333333;
int t,c,d,n,tot,cnt[N],pr[N],vis[N];
int main(){
	ios::sync_with_stdio(0);
	for(int i=2;i<N;i++){
		if(!vis[i])pr[++tot]=i,cnt[i]++;
		for(int j=1;j<=tot&&i*pr[j]<N;j++){
			vis[pr[j]*i]=1;
			cnt[pr[j]*i]=cnt[i]+(bool)(i%pr[j]);
			if(i%pr[j]==0)break;
		}
	}
	for(cin>>t;t--;){
		cin>>c>>d>>n;
		int ans=0;
		for(int i=1;i*i<=n;i++)
			if(n%i==0)
				ans+=((d+i)%c?0:(1<<cnt[(d+i)/c]))+((i*i<n)*((d+n/i)%c?0:(1<<cnt[(d+n/i)/c])));
		cout<<ans<<"\n";
	}
}