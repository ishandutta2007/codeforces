#include<bits/stdc++.h>
#define ll long long
#define N 100005
using namespace std;

int m,n,p,t,f[N],g[N];
void up(int k,int w,int x,int y){
	if (w+(y-x)/p>f[k]){
		f[k]=w+(y-x)/p; g[k]=x+(y-x)/p*p;
	} else if (w+(y-x)/p==f[k]){
		g[k]=min(g[k],x+(y-x)/p*p);
	}
}
int main(){
	scanf("%d%d%d%d",&m,&n,&p,&t);
	int now=0,i,ans=0,x,y;
	g[0]=-t;
	for (i=1; i<=n; i++){
		scanf("%d%d",&x,&y);
		if (now) now--;
		for (; now<i && g[now]+t<=y; now++){
			if (g[now]+t<=x) up(i,f[now],x,y); else up(i,f[now],g[now]+t,y);
		}
		ans=max(ans,f[i]);
		if (f[i-1]>f[i]){ f[i]=f[i-1]; g[i]=g[i-1]; }
		else if (f[i-1]==f[i]) g[i]=min(g[i],g[i-1]);
	}
	printf("%d\n",ans);
	return 0;
}