#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e7+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int f[maxn],g[maxn],kmp[maxn],m,n;
char s[maxn],t[maxn];
inline bool check(int k){
	if(k+m-1>n)return false;
	for(ri i=1;i<=m;++i)
		if(s[k+i-1]!=t[i]&&s[k+i-1]!='?')
			return false;
	return true;
}
signed main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1),m=strlen(t+1);
	for(ri i=2,j=0;i<=m;++i){
		while(j&&t[i]!=t[j+1])j=kmp[j];
		if(t[i]==t[j+1])++j;
		kmp[i]=j;
	}
	for(ri i=1;i<=n;++i){
		f[i]=f[i-1];
		if(check(i)){
			g[i]=f[i-m]+1;
			for(ri j=kmp[m];j;j=kmp[j])ckmax(g[i],g[i-(m-j)]+1);
			ckmax(f[i],g[i]);
		}
	}
	printf("%d",f[n]);
	return 0;
}