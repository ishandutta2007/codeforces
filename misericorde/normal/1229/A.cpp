#include <bits/stdc++.h>
#define ll long long
#define maxn 7005
ll n,b[maxn];
ll ans=0,a[maxn],h[maxn],cnt[maxn]={0};
int vis[maxn]={0};

int main(){
	std::cin>>n;
	for (int i=1;i<=n;++i){std::cin>>a[i];}
	for(int i=1;i<=n;++i)std::cin>>b[i];
	for (int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)if (a[i]==a[j])cnt[i]++;
	} for (int i=1;i<=n;++i)if (cnt[i]>1)vis[i]=1;
	for (int i=1;i<=n;++i){
		if (cnt[i]>1)
			for (int j=1;j<=n;++j){
				if ((a[i]|a[j])==a[i])vis[j]=1;
			}
	}for (int i=1;i<=n;++i)ans+=vis[i]*b[i];
	std::cout<<ans;
	return 0;
}