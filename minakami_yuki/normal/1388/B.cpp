#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
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
int n,m;
int main(){
	int T;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		m=(n+3)/4;
		for(int i=1;i<=n-m;++i) putchar('9');
		for(int i=1;i<=m;++i) putchar('8');
		puts("");
	}
	return 0;
}