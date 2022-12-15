#include <bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LD INF=2e12;
const int N=3e5+10;
const LL P=1e9+7;
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
void get_min(int &x,int y){
    if(x>y) x=y;
}
int n,m;
LL K,bin[70];
int nxt[N];
int q[N];
void ins(int x){
	q[++m]=x;
	if(nxt[x]) ins(nxt[x]);
}
void MAIN(){
	bin[0]=1;for(int i=1;i<=60;++i) bin[i]=bin[i-1]<<1;
	scanf("%d%lld",&n,&K);
	for(int i=1;i<=n;++i) nxt[i]=0;
	if(n<=61&&K>bin[n-1]){
		puts("-1");
		return;
	}
	m=0;
	for(int i=1;i<n;++i){
		if(n-i>61) ins(i);
		else{
			if(bin[n-i-1]>=K) ins(i);
			else {
				K-=bin[n-i-1];
				nxt[i+1]=i;
			}
		}
	}
	ins(n);
	for(int i=1;i<=m;++i) {
		if(i!=1) putchar(' ');
		printf("%d",q[i]);
	}
	puts("");
	return;
}
int main(){
    int T=1;scanf("%d",&T);
    while(T--) MAIN();
	return 0;
}