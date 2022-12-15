#include <bits/stdc++.h>
#define LL long long
using namespace std;
const int N=3e5+10;
const LL INF=1e18;
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
void add(LL &x,LL y){
	x+=y;if(x>=P)x-=P;
}
int n;
char s[N];
char p[N];
int tp;
int main(){
	int T,u,v;scanf("%d",&T);
	while(T--){
		scanf("%s",s+1);n=strlen(s+1);
		tp=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='A'||tp==0){
				p[++tp]=s[i];
			}
			else{
				--tp;
			}
		}
		printf("%d\n",tp);
	}
    return 0;
}