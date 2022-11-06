#include<bits/stdc++.h>
#define N 100005
using namespace std;

int n,m,ans,cnt,a[N],b[N],p[N],tmp;
void ins(int x,int y){
	int i; x=p[x];
	for (i=1; i<=cnt; i++){
		for (; !(x%a[i]); x/=a[i]){
			if (b[i]==1 && y==-1) tmp--;
			if (!b[i] && y==1) tmp++;
			b[i]+=y;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	int i,now=m;
	for (i=2; i*i<=m; i++) if (!(now%i)){
		a[++cnt]=i;
		for (; !(now%i); now/=i) b[cnt]++;
	}
	if (now>1){ a[++cnt]=now; b[cnt]=1; }
	tmp=cnt;
	for (i=1; i<=n; i++) scanf("%d",&p[i]);
	long long ans=0; int j;
	for (i=j=1; i<=n; i++){
		for (; j<=i; j++) ins(j,-1);
		for (; j<=n && tmp>0; j++) ins(j,-1);
		if (!tmp) ans+=n-j+2;
		ins(i,1);
	}
	printf("%lld\n",ans);
	return 0;
}