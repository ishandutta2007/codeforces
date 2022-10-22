#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define ull unsigned long long
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=2e6+10;
const int p=1e9+7; 
int base[2]={19260817,114514123};
inline int inv(int a,int b=p-2){
	int x=1;while(b){
		if(b&1)(x*=a)%=p;
		(a*=a)%=p,b>>=1;
	}return x;
}
int n,k,ans[N];char a[N];int h[N][2],pw[N][2];
int ask(int l,int r,int o){
	return (h[r][o]-h[l-1][o]*pw[r-l+1][o]%p+p)%p;
}
bool get(int l1,int r1,int l2,int r2){
	For(o,0,1)if(ask(l1,r1,o)!=ask(l2,r2,o))return 0;
	return 1;
}
signed main(){
	n=read(),k=read(),scanf("%s",a+1);
	pw[0][0]=pw[0][1]=1;For(i,1,n)For(o,0,1)pw[i][o]=pw[i-1][o]*base[o]%p;
	For(i,1,n)For(o,0,1)h[i][o]=(h[i-1][o]*base[o]%p+a[i])%p;
	int now=0;For(i,1,n/k){
		int j=i*k;//|BA|=i,[1,j]=[1,i]^k
//		printf("[1,%d] = [1,%d]^%d, [%d,%d]%llu [%d,%d]%llu\n",j,i,k,1,j-i,get(1,j-i),i+1,j,get(i+1,j));
		if(get(1,j-i,i+1,j)){
//			printf("[1,%d]\n",i);
			now=max(now,j+1);ans[j]=1;
			while(now-j<=i&&now<=n&&get(1,now-j,j+1,now))ans[now++]=1;
//			int l=j+1,r=j+i;
//			while(l<=r){
//				int m=l+r>>1;
//				if(get(j+1,m,1,m-j))l=m+1;
//				else r=m-1;
//			}ans[j]++,ans[l]--;
		}
	}
	For(i,1,n)putchar(ans[i]?'1':'0');
	return 0;
}