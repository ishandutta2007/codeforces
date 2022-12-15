#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
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
int n; 
int a[N],b[N],c[N];
int p[N];
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		for(int i=1;i<=n;++i) scanf("%d",&b[i]);
		for(int i=1;i<=n;++i) scanf("%d",&c[i]);
		p[1]=a[1];
		for(int i=2;i<n;++i){
			if(a[i]==p[i-1]){
				p[i]=b[i];
			}
			else p[i]=a[i];
		}
		if(a[n]!=p[n-1]&&a[n]!=p[1]) p[n]=a[n];
		else if(b[n]!=p[n-1]&&b[n]!=p[1]) p[n]=b[n];
		else p[n]=c[n];
		for(int i=1;i<=n;++i) printf("%d ",p[i]);puts("");
	} 
	return 0;
}