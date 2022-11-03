#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define X first
#define Y second
const int N=1e6+5,mod=998244353;
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
int n,q;
int num=0;
int a[4][N];
int main(){
	n=read(),q=read();
	for(int i=1;i<=q;i++) {
		int x=read(),y=read();
		if(a[x][y]) {
			if(a[x-1][y-1]) num--;
			if(a[x-1][y]) num--;
			if(a[x-1][y+1]) num--;
			if(a[x+1][y-1]) num--;
			if(a[x+1][y]) num--;
			if(a[x+1][y+1]) num--;
		}else {
			if(a[x-1][y-1]) num++;
			if(a[x-1][y]) num++;
			if(a[x-1][y+1]) num++;
			if(a[x+1][y-1]) num++;
			if(a[x+1][y]) num++;
			if(a[x+1][y+1]) num++;
		}
		if(num) puts("No");else puts("Yes");
		a[x][y]^=1;
	}
	return 0;
}