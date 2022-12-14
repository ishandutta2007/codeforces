#include <cstdio>
#define rpt(i,l,r) for(int i=l;i<=r;i++)
#define N 1000005
int n,m,x,y,d[N],fa[N],c[N],b[N],s[N],cnt,ans;
int father(int x){
	return fa[x]==x?x:fa[x]=father(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	rpt(i,1,n) fa[i]=i,d[i]=c[i]=b[i]=s[i]=0;
	rpt(i,1,m){
		scanf("%d%d",&x,&y);
		fa[father(x)]=father(y);
		d[x]++;d[y]++;
	}
	rpt(i,1,n) if(d[i]&1) c[father(i)]++;
	rpt(i,1,n) s[father(i)]++;
	cnt=0;ans=0;
	rpt(i,1,n){
		x=father(i);
		if(b[x]) continue;
		b[x]=1;
		if(s[x]==1&&d[x]==0&&x!=father(1)) continue;
		cnt++;
		if(c[x]) ans+=c[x]/2-1;
	}
	if(cnt==1&&c[father(1)]==0) printf("%d",0);
	else printf("%d",cnt+ans);
}