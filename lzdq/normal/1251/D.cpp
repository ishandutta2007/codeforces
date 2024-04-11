#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
typedef long long ll;
int n;
ll s;
int x[MAXN],y[MAXN];
int tot,cnt,z[MAXN];
inline bool Check(int sl){
	tot=cnt=0;
	ll sum=0;
	for(int i=1;i<=n;i++){
		if(y[i]>=sl){
			if(x[i]>=sl) cnt++,sum+=x[i];
			else z[++tot]=-x[i];
		}
		else sum+=x[i];
	}
	if(tot+cnt<=n/2) return 0;
	sort(z+1,z+tot+1);
	for(int i=1;i<=tot;i++){
		if(cnt+i-1<=n/2) sum+=sl;
		else sum-=z[i];
	}
	return sum<=s;
}
int main(){
//	freopen("D.in","r",stdin);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d%I64d",&n,&s);
		for(int i=1;i<=n;i++)
			scanf("%d%d",x+i,y+i);
		int l=1,r=1e9;
		while(l<r){
			const int mid=l+r+1>>1;
			if(Check(mid)) l=mid;
			else r=mid-1;
		}
		printf("%d\n",r);
	}
	return 0;
}