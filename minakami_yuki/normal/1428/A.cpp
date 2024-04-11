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
LL a,b,c,d;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d);
		a=abs(a-c);
		b=abs(b-d);
		if(a>0&&b>0){
			printf("%I64d\n",a+b+2);
		}
		else printf("%I64d\n",a+b);
	}
    return 0;
}