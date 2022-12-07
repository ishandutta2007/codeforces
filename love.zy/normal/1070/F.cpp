#include <bits/stdc++.h>
#define MAXN 400010
using namespace std;
int n,a[MAXN],b[MAXN],c[MAXN],d[MAXN];
int sa[MAXN],sb[MAXN],sc[MAXN],sd[MAXN];
int na,nb,nc,nd;

bool cmp(int x,int y)
{
	return x>y;
}

void f(int n,int a[],int sum[])
{
	int i;
	for(i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
}

int getsum(int sum[],int l,int r)
{
	if(r<l) return 0;
	return sum[r]-sum[l-1];
}

int main()
{
	int i,t,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d%d",&t,&x);
		if(t==11) a[++na]=x;
		if(t==10) b[++nb]=x;
		if(t==1) c[++nc]=x;
		if(t==0) d[++nd]=x;
	}
	sort(a+1,a+na+1,cmp);f(na,a,sa);
	sort(b+1,b+nb+1,cmp);f(nb,b,sb);
	sort(c+1,c+nc+1,cmp);f(nc,c,sc);
	sort(d+1,d+nd+1,cmp);f(nd,d,sd);
	int ans=0,tmp;
	for(i=0;i<=min(na,nd);i++){
		int dd=na-i;
		if(nc>=nb-dd){
			tmp=getsum(sa,1,na);
			tmp+=getsum(sb,1,nb);
			tmp+=getsum(sc,1,min(nb+dd,nc));
			tmp+=getsum(sd,1,i);
			ans=max(tmp,ans);
			//if(tmp==104) printf(" %d %d %d\n",nb,min(nb+dd,nc),i);
		}
		if(nb>=nc-dd){
			tmp=getsum(sa,1,na);
			tmp+=getsum(sb,1,min(nc+dd,nb));
			tmp+=getsum(sc,1,nc);
			tmp+=getsum(sd,1,i);
			ans=max(tmp,ans);
			//if(tmp==104) printf(" %d %d %d\n",min(nc+dd,nb),nc,i);
		}
	}
	printf("%d\n",ans);
 return 0;
}