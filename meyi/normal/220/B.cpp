#include<bits/stdc++.h>
using namespace std;
#define ri register int
const int maxn=1e5+10,maxp=451;
vector<int>v;
map<int,int>cnt;
int a[maxn],ans,l,m,n,sum[maxp][maxn],r;
int main(){
	scanf("%d%d",&n,&m);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		if(++cnt[a[i]]==a[i])v.push_back(a[i]);
	}
	for(ri i=1;i<=n;++i)
		for(ri j=0;j<v.size();++j)
			sum[j][i]=sum[j][i-1]+(a[i]==v[j]);
	while(m--){
		scanf("%d%d",&l,&r);
		ans=0;
		for(ri i=0;i<v.size();++i)ans+=(sum[i][r]-sum[i][l-1]==v[i]);
		printf("%d\n",ans);
	}
	return 0;
}