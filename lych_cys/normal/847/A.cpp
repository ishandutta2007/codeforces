#include<bits/stdc++.h>
#define N 109
using namespace std;

int n,tp,p[N],q[N],fa[N],pre[N],nxt[N]; bool v1[N],v2[N];
int getfa(int x){ return (x==fa[x])?x:fa[x]=getfa(fa[x]); }
int main(){
	scanf("%d",&n);
	int i;
	for (i=1; i<=n; i++){
		scanf("%d%d",&pre[i],&nxt[i]);
		if (pre[i]) nxt[pre[i]]=i; if (nxt[i]) pre[nxt[i]]=i;
	}
	for (i=1; i<=n; i++) if (!pre[i]) p[++tp]=i;
	tp=0;
	for (i=1; i<=n; i++) if (!nxt[i]) q[++tp]=i;
	if (tp==1){
		for (i=1; i<=n; i++) printf("%d %d\n",pre[i],nxt[i]); return 0;
	}
	for (i=1; i<=n; i++) fa[i]=i;
	for (i=1; i<=n; i++) if (pre[i]) fa[getfa(pre[i])]=getfa(i);
	for (i=1; i<=tp; i++)
		for (int j=1; j<=tp; j++) if (!v1[i] && !v2[j] && getfa(p[i])!=getfa(q[j])){
			fa[getfa(p[i])]=getfa(q[j]);
			v1[i]=v2[j]=1;
			pre[p[i]]=q[j]; nxt[q[j]]=p[i];
		}
	for (i=1; i<=n; i++) printf("%d %d\n",pre[i],nxt[i]);
	return 0;
}