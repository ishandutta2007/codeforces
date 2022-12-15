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

bool vis[N];
int main(){
	int T,u,v;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		bool f1=0,f2=0;
		for(int i=1;i<=n;++i){
			if(s[i]=='>') f1=1;
			if(s[i]=='<') f2=1;
			vis[i]=0;
		}
		if(f1==0||f2==0){
			printf("%d\n",n);
			continue;
		}
		int ans=0;
		for(int i=1;i<=n;++i){
			u=i+1;
			if(u>n) u=1;
			if(s[i]=='-') {
				vis[i]=1;
				vis[u]=1;
			}
		}
		for(int i=1;i<=n;++i) if(vis[i]) ++ans;
		printf("%d\n",ans);
	}
    return 0;
}