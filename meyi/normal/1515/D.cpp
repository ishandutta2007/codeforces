#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define SZ(k) k.size()
#define ALL(k) k.begin(),k.end()
#define DEBUG(k...) fprintf(stderr,k)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int> pii;
template<class T>inline bool chkmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chkmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],b[maxn],cnt1[maxn],cnt2[maxn],l,m,n,r,t_case;
inline bool cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%d",&n,&l,&r);
		memset(cnt1,0,sizeof cnt1);
		memset(cnt2,0,sizeof cnt2);
		ri ans=max(l,r);
		for(ri i=1;i<=l;++i)scanf("%d",a+i),++cnt1[a[i]];
		for(ri i=1;i<=r;++i){
			scanf("%d",b+i);
			if(cnt1[b[i]])--cnt1[b[i]],--ans;
			else ++cnt2[b[i]];
		}
		ri tmp=0;
		if(l<r){
			sort(cnt2+1,cnt2+n+1,cmp);
			for(ri i=1;i<=n&&cnt2[i];++i)tmp+=cnt2[i]/2;
		}
		else if(l>r){
			sort(cnt1+1,cnt1+n+1,cmp);
			for(ri i=1;i<=n&&cnt1[i];++i)tmp+=cnt1[i]/2;
		}
		printf("%d\n",ans-min(abs(l-r)/2,tmp));
	}
	return 0;
}