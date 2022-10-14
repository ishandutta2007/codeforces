#include<bits/stdc++.h>
using namespace std;
int const N=200010;
int t,n,a[N],p[N],f[N],g[N],l[N],r[N],cnt[N],pre[N];
vector<int>b;
int main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n,b.clear();
		for(int i=1;i<=n;i++)
			cin>>a[i],b.push_back(a[i]),
			l[i]=r[i]=pre[i]=p[i]=f[i]=g[i]=cnt[i]=0;
		sort(b.begin(),b.end());
		b.erase(unique(b.begin(),b.end()),b.end());
		for(int i=1;i<=n;i++)
			a[i]=lower_bound(b.begin(),b.end(),a[i])-b.begin()+1;
		for(int i=1;i<=n;i++)
			r[a[i]]=i,cnt[a[i]]++;
		for(int i=n;i>=1;i--)
			l[a[i]]=i;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(!pre[a[i]])
				pre[a[i]]=i;
			p[i]=p[pre[a[i]]]+1;
			f[i]=max(f[pre[a[i]]],
				max(p[pre[a[i]-1]],g[pre[a[i]-1]]))+1;
			if(i==r[a[i]])
				g[i]=f[l[a[i]]]+cnt[a[i]]-1;
			pre[a[i]]=i;
			ans=max(ans,max(f[i],max(g[i],p[i])));
		}
		cout<<n-ans<<"\n";
	}
}