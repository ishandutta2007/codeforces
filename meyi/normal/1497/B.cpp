#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
int a,ans,m,n,t,v[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		memset(v,0,sizeof v);
		for(ri i=1;i<=n;++i)scanf("%d",&a),++v[a%m];
		ans=(v[0]>0);
		for(ri i=1;i<((m+1)>>1);++i){
			if(v[i]<v[m-i])swap(v[i],v[m-i]);
			if(!v[i])continue;
			if(v[i]==v[m-i])++ans;
			else ans+=v[i]-v[m-i];
		}
		if(m%2==0)ans+=(v[m>>1]>0);
		printf("%d\n",ans);
	}
	return 0;
}