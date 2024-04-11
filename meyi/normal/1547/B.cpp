#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int m,n,pos[maxn],t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		bool flag=false;
		for(ri i=1;i<=n;++i){
			if(pos[s[i]]){
				flag=true;
				break;
			}
			pos[s[i]]=i;
		}
		if(flag){
			puts("NO");
		}
		else{
			for(int i='a',l=pos['a'],r=pos['a'];i<'a'+n;++i){
				if(!pos[i]){
					flag=true;
					break;
				}
				if(i=='a')continue;
				if(pos[i]+1==l)l=pos[i];
				else if(pos[i]-1==r)r=pos[i];
				else{
					flag=true;
					break;
				}
			}
			puts(flag?"NO":"YES");
		}
		for(ri i=1;i<=n;++i)pos[s[i]]=0,s[i]=0;
	}
	return 0;
}