#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233333;
int t,n,m,a[N],b[N],f[N],s[N];
vector<int>e[N];
int find(int x){
	return x^f[x]?f[x]=find(f[x]):x;
}
void work(int x){
	s[x]=0,f[x]=find(x+1);
	for(int y:e[x])
		if(!s[y])
			for(int p=find(min(x,y));p<=max(x,y);p=find(p))
				work(p);
}
signed main(){
	ios::sync_with_stdio(0);
	for(cin>>t;t--;){
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=n;i++)
			cin>>b[i],s[i]=s[i-1]+a[i]-b[i];
		for(int i=0;i<=n+1;i++)
			e[i].clear(),f[i]=i;
		for(int x,y;m--;)
			cin>>x>>y,e[x-1].push_back(y),e[y].push_back(x-1);
		for(int i=0;i<=n;i++)
			if(!s[i])work(i);
		int flg=1;
		for(int i=1;i<=n;i++)
			flg&=!s[i];
		cout<<(flg?"YES\n":"NO\n");
	}
}