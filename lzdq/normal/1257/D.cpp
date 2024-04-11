#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=2e5+5;
struct node{
	int p,s;
}he[MAXN];
bool operator <(node a,node b){
	return a.s<b.s;
}
int n,m,a[MAXN][20];
int lg[MAXN],mx[MAXN];
int calc(int l,int r){
	return max(a[l][lg[r-l+1]],a[r-(1<<lg[r-l+1])+1][lg[r-l+1]]);
}
int ans;
bool Check(int l,int r){
	int w=lower_bound(he+1,he+m+1,(node){0,r-l+1})-he;
	return /*printf("w %d %d calc %d %d = %d\n",w,mx[w],l,r,calc(l,r)),*/mx[w]>=calc(l,r);
}
int main(){
//	freopen("D.in","r",stdin);
	int t;scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		lg[0]=-1;
		for(int i=1;i<=n;i++)
			scanf("%d",a[i]),lg[i]=lg[i>>1]+1;
		for(int j=1;j<20;j++)
			for(int i=1;i+(1<<j)-1<=n;i++)
				a[i][j]=max(a[i][j-1],a[i+(1<<j-1)][j-1]);
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&he[i].p,&he[i].s);
		sort(he+1,he+m+1);
		mx[m+1]=0;
		for(int i=m;i;i--)
			mx[i]=max(mx[i+1],he[i].p);
		if(calc(1,n)>mx[1]){
			puts("-1");
			continue;
		}
		ans=0;
		for(int i=0;i<n;){
			int w=i+1;
			while(w<=n&&Check(i+1,w)) w++;
			i=w-1;
			ans++;
//			printf("i %d\n",i);
		}
		printf("%d\n",ans);
	}
	return 0;
}