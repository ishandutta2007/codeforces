#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
typedef long long ll;
using namespace std;
const int MAXN=1e6+5;
int n,m,a[MAXN],b[MAXN],c[MAXN],cnt[MAXN];
int d[MAXN];
vector<int> v[MAXN];
#define lc k<<1
#define rc k<<1|1
#define ls lc,l,mid
#define rs rc,mid+1,r
int sum[MAXN<<2],mi[MAXN<<2];
inline void pushup(int k){
	sum[k]=sum[lc]+sum[rc];
	mi[k]=min(mi[lc],sum[lc]+mi[rc]);
}
void Build(int k,int l,int r){
	if(l==r){
		sum[k]=1;
		mi[k]=0;
		return ;
	}
	int mid=l+r>>1;
	Build(ls);
	Build(rs);
	pushup(k);
	return ;
}
void Modify(int k,int l,int r,int x,int y){
	if(l==r){
		sum[k]=y;
		mi[k]=min(0,y);
		return ;
	}
	int mid=l+r>>1;
	if(x<=mid) Modify(ls,x,y);
	else Modify(rs,x,y);
	pushup(k);
	return ;
}
int rsum[MAXN];
inline int Query(int x){
	int res=0;
	for(int i=x; i; i-=i&-i)
		res+=rsum[i];
	return res;
}
inline void Add(int x){
	for(int i=x; i<=*d; i+=i&-i)
		rsum[i]++;
}
ll ans;
int main(){
	//freopen("in1.txt","r",stdin);
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d%d",&n,&m);
		for(int i=1; i<=n; i++)
			scanf("%d",a+i),d[i]=a[i],v[i].clear(),rsum[i]=0;
		for(int i=1; i<=m; i++)
			scanf("%d",b+i),cnt[i]=0,c[i]=b[i];
		sort(d+1,d+n+1);
		*d=unique(d+1,d+n+1)-d-1;
		for(int i=1; i<=n; i++)
			v[a[i]=lower_bound(d+1,d+*d+1,a[i])-d].push_back(i);
		sort(b+1,b+m+1);
		*b=unique(b+1,b+m+1)-b-1;
		for(int i=1; i<=m; i++)
			cnt[lower_bound(b+1,b+*b+1,c[i])-b]++;
		ans=0;
		for(int i=n; i; i--){
			ans+=Query(a[i]-1);
			Add(a[i]);
		}
		Build(1,1,n);
		for(int i=1,j=1,x; i<=*b; i++){
			x=b[i];
			while(j<=*d&&d[j]<x){
				for(int k=0; k<v[j].size(); k++)
					Modify(1,1,n,v[j][k],-1);
				j++;
			}
			if(j<=*d&&d[j]==x){
				for(int k=0; k<v[j].size(); k++)
					Modify(1,1,n,v[j][k],0);
			}
			ans+=1ll*(mi[1]+Query(lower_bound(d+1,d+*d+1,x)-d-1))*cnt[i];
			//printf("i %d\n",i);
		}
		printf("%lld\n",ans);
	}
	return 0;
}