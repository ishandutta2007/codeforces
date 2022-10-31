#include<cstdio>
#include<algorithm>
#define MAXN 100000
using namespace std;
template<class T>
void Read(T &x){
	char c;
	bool f(0);
	while(c=getchar(),c!=EOF){
		if(c=='-')
			f=1;
		else if(c>='0'&&c<='9'){
			x=c-'0';
			while(c=getchar(),c>='0'&&c<='9')
				x=x*10+c-'0';
			ungetc(c,stdin);
			if(f)
				x=-x;
			return;
		}
	}
}
int n,a[MAXN+10],b[MAXN+10],fa[MAXN+10];
long long val[MAXN+10],ans[MAXN+10];
bool vis[MAXN+10];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void Union(int x,int y){
	x=find(x);
	y=find(y);
	fa[x]=y;
}
int main()
{
	Read(n);
	int i;
	long long nw;
	for(i=1;i<=n;i++){
		fa[i]=i;
		Read(a[i]);
	}
	for(i=1;i<=n;i++)
		Read(b[i]);
	for(i=n;i;i--){
		nw=a[b[i]];
		if(vis[b[i]+1]){
			nw+=val[find(b[i]+1)];
			Union(b[i],b[i]+1);
		}
		if(vis[b[i]-1]){
			nw+=val[find(b[i]-1)];
			Union(b[i],b[i]-1);
		}
		val[find(b[i])]=nw;
		ans[i-1]=max(ans[i],nw);
		vis[b[i]]=1;
	}
	for(i=1;i<=n;i++)
		printf("%I64d\n",ans[i]);
}