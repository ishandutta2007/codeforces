#include<bits/stdc++.h>
#define ll long long
#define N 505
using namespace std;

int n,aa,bb; ll s[N],c[N],a[N][N];
int read(){
	int x=0; char cr=getchar(); bool flag=0;
	while (cr<'0' || cr>'9'){ if (cr=='-') flag=1; cr=getchar(); }
	while (cr>='0' && cr<='9'){ x=x*10+cr-'0'; cr=getchar(); }
	return (flag)?-x:x;
}
int main(){
	scanf("%d",&n);
	if (n==1){puts("1");return 0; }
	int i,j; ll t1=0,t2=0;
	for (i=1; i<=n; i++)
		for (j=1; j<=n; j++){
			scanf("%lld",&a[i][j]);
			if (!a[i][j]){ aa=i; bb=j; }
			s[i]+=a[i][j]; c[j]+=a[i][j];
			if (i==j) t1+=a[i][j];
				if (i+j==n+1) t2+=a[i][j];
		}
		ll tmp;
		if (aa!=bb) tmp=t1; else if (aa+bb!=n+1) tmp=t2; else{
	for (i=1; i<=n; i++){
		if (i!=aa){ tmp=s[i]; break;}
		if (i!=bb){ tmp=c[i]; break;}
	}}
	a[aa][bb]=tmp-s[aa];
	s[aa]+=a[aa][bb]; c[bb]+=a[aa][bb];
	if (aa==bb) t1+=a[aa][bb]; if (aa+bb==n+1) t2+=a[aa][bb];
	for (i=1; i<=n; i++)
		if (s[i]!=tmp || c[i]!=tmp || t1!=tmp || t2!=tmp){puts("-1");return 0; }
	if (a[aa][bb]<=0){ puts("-1"); }else printf("%lld\n",a[aa][bb]);
}