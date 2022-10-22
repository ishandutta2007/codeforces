#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a[maxn],m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		bool flag=true;
		for(ri i=1;i<=n;++i)s[i]^=48,flag&=(s[i]&1);
		if(flag)puts("-1");
		else if(!(s[n]&1))puts("0");
		else if(!(s[1]&1))puts("1");
		else puts("2");
		clear(s,n);
	}
	return 0;
}