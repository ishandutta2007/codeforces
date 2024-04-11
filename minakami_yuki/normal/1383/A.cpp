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
int n; 
char s[N],t[N];
int f[25][25];
int main(){
	int T,x,y,k,ans;scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ans=0;
		scanf("%s",s+1);
		scanf("%s",t+1);
		bool flag=0;
		for(int i=1;i<=n;++i){
			if(s[i]>t[i]){
				flag=1;break;
			}
		}
		if(flag){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=20;++i) for(int j=1;j<=20;++j) f[i][j]=0;
		for(int i=1;i<=n;++i){
			x=s[i]-'a'+1;y=t[i]-'a'+1;
			f[x][y]=1;
		}
		for(int i=1;i<=20;++i){
			for(k=i;k<=20;++k)
				if(f[i][k]&&k>i) break;
			if(k>20) continue;
			++ans;
			for(int j=k;j<=20;++j) f[k][j]|=f[i][j];
		}
		printf("%d\n",ans);
	}
	return 0;
}