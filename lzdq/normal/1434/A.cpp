#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=6e5+5;
int n,a[10],b[MAXN];
struct node{
	int w,x;
	node(int a=0,int b=0){
		w=a,x=b;
	}
}c[MAXN];
bool operator <(node a,node b){
	return a.w<b.w;
}
int tot,cnt[MAXN];
int main(){
	for(int i=1; i<=6; i++)
		scanf("%d",a+i);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",b+i);
		for(int j=1; j<=6; j++)
			c[++tot]=node(b[i]-a[j],i);
	}
	int ans=2e9;
	sort(c+1,c+tot+1);
	for(int i=1,j=1,k=0;i<=tot;i++){
		if(cnt[c[i].x]++==0) k++;
		while(j<tot&&k==n&&cnt[c[j].x]>1){
			cnt[c[j].x]--;
			j++;
		}
		if(k==n) ans=min(ans,c[i].w-c[j].w);
	}
	printf("%d\n",ans);
	return 0;
}