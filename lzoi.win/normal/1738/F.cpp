#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cassert>
using namespace std;
typedef long long ll;
const int MAXN=1005;
int n,d[MAXN],p[MAXN],pre[MAXN],s1[MAXN],s2[MAXN];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
inline bool cmp(int x,int y){
	return d[x]>d[y];
}
int main(){
	int _; scanf("%d",&_);
	while(_--){
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",d+i);
		for(int i=1; i<=n; i++)
			pre[i]=i,p[i]=i,s1[i]=1,s2[i]=d[i];
		sort(p+1,p+n+1,cmp);
		for(int i=1; i<=n; i++){
			int u=p[i];
			if(pre[u]!=u) continue;
			for(int _=0; _<d[u]; _++){
				printf("? %d\n",u);
				fflush(stdout);
				int v;
				scanf("%d",&v);
				if(s1[fnd(v)]>1){
					int x=u,y=fnd(v);
					if(d[x]>d[y]) swap(x,y);
					pre[x]=y;
					s1[y]+=s1[x];
					s2[y]+=s2[x];
					break;
				}
				pre[v]=u;
				s1[u]+=s1[v];
				s2[u]+=s2[v];
			}
		}
		/*
		int cnt=0;
		while(1){
			int w=0;
			for(int i=1; i<=n; i++)
				if(i==pre[i]&&s1[i]*s1[i]<s2[i])
					if(!w||d[i]>d[w]) w=i;
			if(!w) break;
			assert(++cnt<=n);
			printf("? %d\n",w);
			fflush(stdout);
			int u=w,v;
			scanf("%d",&v);
			int x=fnd(u),y=fnd(v);
			if(x!=y){
				if(d[x]>d[y]) swap(x,y);
				pre[x]=y;
				s1[y]+=s1[x];
				s2[y]+=s2[x];
			}
		}
		*/
		putchar('!');
		for(int i=1; i<=n; i++)
			printf(" %d",fnd(i));
		puts("");
		fflush(stdout);
	}
	return 0;
}