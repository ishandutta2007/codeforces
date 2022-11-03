#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=105,mod=998244353;
inline int pls(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int dec(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=mul(a,a)) if(b&1) res=mul(res,a);
	return res;
}
inline void chkmin(int &x,int y){
	if(y<x) x=y;
}
int n;
int p[N];
int f[N][N][N][2];
int main(){
	n=read();
	int c0=n/2,c1=n-c0;
	p[0]=-1;
	for(int i=1;i<=n;i++) {
		p[i]=read();
		if(p[i]!=0) {
			if(p[i]%2==0) c0--;
			else c1--;
			p[i]=p[i]%2;
		}else p[i]=-1;
	}
	memset(f,0x3f,sizeof(f));
	f[0][0][0][0]=f[0][0][0][1]=0;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=c0;j++)
			for(int k=0;k<=c1&&j+k<=i;k++) {
				if(p[i]!=-1) {
					if(p[i-1]!=1) chkmin(f[i][j][k][p[i]],f[i-1][j][k][0]+(p[i]==1));
					if(p[i-1]!=0) chkmin(f[i][j][k][p[i]],f[i-1][j][k][1]+(p[i]==0));
				}else {
					if(j>0) {
						if(p[i-1]!=-1) chkmin(f[i][j][k][0],f[i-1][j-1][k][p[i-1]]+(p[i-1]==1));
						else {
							chkmin(f[i][j][k][0],f[i-1][j-1][k][0]);
							chkmin(f[i][j][k][0],f[i-1][j-1][k][1]+1);
						}
					}
					if(k>0) {
						if(p[i-1]!=-1) chkmin(f[i][j][k][1],f[i-1][j][k-1][p[i-1]]+(p[i-1]==0));
						else {
							chkmin(f[i][j][k][1],f[i-1][j][k-1][0]+1);
							chkmin(f[i][j][k][1],f[i-1][j][k-1][1]);
						}
					}
				}
				//cout<<i<<' '<<j<<' '<<k<<' '<<f[i][j][k][0]<<' '<<f[i][j][k][1]<<endl; 
			} 
	printf("%d\n",min(f[n][c0][c1][0],f[n][c0][c1][1]));
	return 0;
}