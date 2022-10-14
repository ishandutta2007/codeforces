#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010;
int t,n,a[N],sp[N],sf[N];
map<int,int>pos;
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,sp[0]=sf[n+1]=0;
		pos.clear();
		for(int i=1;i<=n;i++)
			cin>>a[i],sp[i]=sp[i-1]+a[i];
		for(int i=n;i>=1;i--)
			sf[i]=sf[i+1]+a[i],pos[sf[i]]=i;
		int ans=0;
		for(int i=1;i<=n;i++)
			if(pos.count(sp[i])&&pos[sp[i]]>i)
				ans=max(ans,i+n-pos[sp[i]]+1);
		cout<<ans<<"\n";
	}
	return 0;
}