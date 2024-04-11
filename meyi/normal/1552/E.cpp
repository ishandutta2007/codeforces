#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],d,k,m,n,t_case;
vector<int>pos[maxn];
inline bool cmp(const vector<int> &x,const vector<int> &y){
	return x[d]<y[d];
}
typedef pair<int,int> pii;
pii ans[maxn];
signed main(){
	scanf("%d%d",&n,&k);
	for(ri i=1;i<=n*k;++i){
		scanf("%d",a+i);
		pos[a[i]].push_back(i);
	}
	m=(n+k-2)/(k-1);
	for(ri i=1,sum=0;i<=n;++i){
		d=i;
		sort(pos+sum+1,pos+n+1,cmp);
		for(ri j=sum+1;j<=min(sum+m,n);++j)ans[a[pos[j][0]]]={pos[j][i-1],pos[j][i]};
		sum+=m;
		if(sum>=n)break;
	}
	for(ri i=1;i<=n;++i)printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}