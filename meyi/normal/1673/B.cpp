#include<bits/stdc++.h>
using namespace std;
#define ri int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
const int maxn=2e5+10;
int cnt[maxn][26],m,n,pre[26],t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(pre,0,sizeof pre);
		for(ri i=1;i<=n;++i){
			memcpy(cnt[i],cnt[i-1],sizeof cnt[i]);
			s[i]-='a';
			++cnt[i][s[i]];
		}
		for(ri i=1;i<=n;++i){
			if(pre[s[i]]){
				for(ri j=0;j<26;++j)
					if(cnt[n][j]&&cnt[i][j]==cnt[pre[s[i]]-1][j]){
						puts("NO");
						goto skip;
					}
			}
			pre[s[i]]=i;
		}
		puts("YES");
		skip:;
	}
	return 0;
}