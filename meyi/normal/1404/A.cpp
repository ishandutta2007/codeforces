#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=3e5+10;
int a[maxn],k,n,t_case;
char s[maxn];
inline void solve(){
	scanf("%d%d%s",&n,&k,s+1);
	for(ri i=1;i<=k;++i){
		char ch='?';
		for(ri j=i;j<=n;j+=k)
			if(s[j]!=ch){
				if(ch=='?')ch=s[j];
				else if(s[j]!='?'){puts("NO");return;}
			}
		for(ri j=i;j<=n;j+=k)s[j]=ch;
	}
	int cnt0=0,cnt1=0;
	for(ri i=1;i<=n;++i){
		if(s[i]=='?')++cnt0;
		if(s[i]=='1')++cnt1;
		if(i>k){
			if(s[i-k]=='?')--cnt0;
			if(s[i-k]=='1')--cnt1;
		}
		if(i>=k){
			if(cnt1<=k/2&&k/2<=cnt1+cnt0);
			else{puts("NO");return;}
		}
	}
	puts("YES");
}
int main(){
	scanf("%d",&t_case);
	while(t_case--)solve();
	return 0;
}