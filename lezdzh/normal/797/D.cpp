#include<cstdio>
#include<algorithm>

using namespace std;

int c[100001],l[100001],r[100001],vis[100001],a[100001];
int f(int o,int ll,int rr){
	if(!~o)return rr-ll+1;
	int x=lower_bound(a+ll,a+rr+1,c[o])-a,y=x-1;
	while(y<rr&&a[y+1]==c[o])y++;
	return f(l[o],ll,x-1)+f(r[o],y+1,rr);
}
int main(){
	int n;scanf("%d",&n);for(int i=1;i<=n;i++)
		scanf("%d%d%d",c+i,l+i,r+i),vis[l[i]]=vis[r[i]]=1,a[++a[0]]=c[i];
	int o;for(int i=1;i<=n;i++)if(!vis[i])o=i;
	sort(a+1,a+n+1);
	printf("%d",f(o,1,n));
}