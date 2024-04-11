#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5,mod=998244353;
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
int T,n;
char s[N];
int main(){
	T=read();
	while(T--) {
		n=read();
		scanf("%s",s+1);
		int ans=0;
		for(int i=1;i<=n;i++)
			if(s[i]=='A'){
				for(int j=i+1;j<=n;j++){
					if(s[j]=='A') break;
					ans=max(ans,j-i);
				}
			}
		printf("%d\n",ans);
	}
	return 0;
}