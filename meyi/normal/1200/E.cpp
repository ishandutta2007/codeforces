#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int kmp[maxn],n,t_case;
char ans[maxn],s[maxn];
signed main(){
	scanf("%d%s",&t_case,ans+1);
	n=strlen(ans+1);
	while(--t_case){
		scanf("%s",s+1);
		ri len=strlen(s+1),tmp=len;
		s[++len]='#';
		for(ri i=n-min(len,n)+1;i<=n;++i)s[++len]=ans[i];
		for(ri i=2,j=0;i<=len;++i){
			while(j&&s[i]!=s[j+1])j=kmp[j];
			if(s[i]==s[j+1])++j;
			kmp[i]=j;
		}
		for(ri i=kmp[len]+1;i<=tmp;++i)ans[++n]=s[i];
		clear(s,len);
	}
	puts(ans+1);
	return 0;
}