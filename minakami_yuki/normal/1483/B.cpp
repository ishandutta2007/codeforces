#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
const int INF=1e9;
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
int gcd(int x,int y){
	return y==0?x:gcd(y,x%y);
}
int n,m;
int a[N],nxt[N],de[N];
int tp;
int q[N];
int find(int x){
	return de[x]==x?x:de[x]=find(de[x]);
}
void MAIN(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
    	scanf("%d",&a[i]);
    	nxt[i]=i+1;
    	de[i]=i;
	}
	de[n+1]=n+1;
	nxt[n]=1;
	tp=0;
	int now=1,las=n,x,y,z;
	while(1){
		if(las==0) break;
		now=find(now);
		if(now==n+1) now=1;
		now=find(now);
		if(now==n+1) break;
		
		x=nxt[now];
		z=gcd(a[now],a[x]);
		if(z>1){
			de[now]=now+1;
			continue;
		}
		--las;
		if(de[x]==x) de[x]=x+1;
		nxt[now]=nxt[x];
		q[++tp]=x;
		now=nxt[now];
	}
	printf("%d",tp);
	for(int i=1;i<=tp;++i) printf(" %d",q[i]);
	puts("");
	return;
}

int main(){
    int ttt=read();
    while(ttt--) MAIN();
    return 0;
}