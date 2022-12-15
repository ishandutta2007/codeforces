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
char a[N],b[N],c[N],d[N];
void MAIN(){
	scanf("%d",&n);
	scanf("%s",a+1);
	scanf("%s",b+1);
	scanf("%s",c+1);
	int A=0,B=0,C=0;
	for(int i=1;i<=n+n+n;++i) d[i]='0';
	for(int i=1;i<=n+n;++i){
		if(a[i]=='1') ++A;
		if(b[i]=='1') ++B;
		if(c[i]=='1') ++C;
	}
	if(B<C){
		swap(C,B);
		for(int i=1;i<=n+n;++i) swap(c[i],b[i]);
		//swap(c,b);
	}
	if(A<B){
		swap(A,B);
		for(int i=1;i<=n+n;++i) swap(a[i],b[i]);
		//swap(a,b);
	}
	if(B<C){
		swap(C,B);
		for(int i=1;i<=n+n;++i) swap(c[i],b[i]);
	}
	int i=1,j=1;
	if(A>=n&&B>=n){
		m=0;
		while(i<=n+n||j<=n+n){
			if(i<=n+n&&a[i]=='0'){
				d[++m]='0';++i;continue;
			}
			if(j<=n+n&&b[j]=='0'){
				d[++m]='0';++j;continue;
			}
			if(i<=n+n&&j<=n+n&&a[i]=='1'&&b[j]=='1'){
				d[++m]='1';++i;++j;continue;
			}
			if(i<=n+n){
				d[++m]=a[i];++i;continue;
			}
			if(j<=n+n){
				d[++m]=b[j];++j;continue;
			}
		}
		
	}
	else {
		m=0;
		while(i<=n+n||j<=n+n){
			if(i<=n+n&&c[i]=='1'){
				d[++m]='1';++i;continue;
			}
			if(j<=n+n&&b[j]=='1'){
				d[++m]='1';++j;continue;
			}
			if(i<=n+n&&j<=n+n&&c[i]=='0'&&b[j]=='0'){
				d[++m]='0';++i;++j;continue;
			}
			if(i<=n+n){
				d[++m]=c[i];++i;continue;
			}
			if(j<=n+n){
				d[++m]=b[j];++j;continue;
			}
		}
		
	}
	for(int i=1;i<=n+n+n;++i) putchar(d[i]);
	puts("");
	return;
}
int main(){
    int T=1;scanf("%d",&T);
    while(T--) MAIN();
	return 0;
}