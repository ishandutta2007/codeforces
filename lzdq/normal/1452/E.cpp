#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=2e3+5;
int n,m,k;
int ans;
int sum[MAXN],f[MAXN];
struct node{
	int x,y;
	int l,r;
	inline void Init(){
		scanf("%d%d",&x,&y);
		if(y-x+1>k){
			l=x;
			r=y-k+1;
			x=x-k+1;
		}else{
			l=y-k+1;
			r=x;
			x=x-k+1;
		}
		int s=0;
		//printf("x %d y %d l %d r %d\n",x,y,l,r);
		for(int i=x; i<=y; i++){
			if(i<=l) s++;
			if(i>r) s--;
			if(i>0&&i<=n) f[i]+=s;
			//printf("i %d s %d\n",i,s);
		}
	}
}a[MAXN];
inline void add(int l,int r,int x){
	//printf("add %d %d %d\n",l,r,x);
	if(r<=0||l>n) return ;
	sum[l]+=x;
	sum[r+1]-=x;
}
int main(){
	//freopen("in1.txt","r",stdin);
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=m; i++)
		a[i].Init();
	for(int i=-n; i+k-1<=n; i++){
		memset(sum,0,sizeof(sum));
		//printf("i %d\n",i);
		for(int j=1; j<=m; j++){
			int l=a[j].l,r=a[j].r;
			if(i-1>=l&&i<=r||i>a[j].y+1||i<a[j].x) continue;
			//printf("j %d\n",j);
			if(i<=l){
				add(1,i-1,1);
				add(r+l-i+1,n,1);
			}else{
				add(1,r+l-i,-1);
				add(i,n,-1);
			}
		}
		for(int j=1; j<=n; j++)
			sum[j]+=sum[j-1],f[j]+=sum[j],ans=max(ans,f[j]);
		//printf("ans %d\n",ans);
	}
	printf("%d\n",ans);
	return 0;
}