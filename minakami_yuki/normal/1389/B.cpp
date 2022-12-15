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
int n,k,z,ans;
int a[N];
int f[N][8][2];
int main(){
	int T,y;scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&z);ans=0;
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		f[1][0][1]=a[1];
		for(int j=0;j<=z;++j){
			for(int i=2;i<=n;++i){
				f[i][j][1]=max(f[i][j][1],f[i-1][j][0]+a[i]);
				f[i][j][1]=max(f[i][j][1],f[i-1][j][1]+a[i]);
			}
			if(j+1<=z)
			for(int i=2;i<=n;++i)
				f[i-1][j+1][0]=max(f[i-1][j+1][0],f[i][j][1]+a[i-1]);
		}
		for(int j=0;j<=z;++j){
			for(int i=1;i<=n;++i){
				y=i-1+j*2;
				if(y==k) {
					ans=max(ans,f[i][j][1]);
					ans=max(ans,f[i][j][0]);
				}
				f[i][j][1]=f[i][j][0]=0;
			}
		}
		printf("%d\n",ans);
	} 
	return 0;
}