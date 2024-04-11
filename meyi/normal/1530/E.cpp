#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline void ckmax(int &x,const int &y){if(x<y)x=y;}
template<class T>inline void ckmin(int &x,const int &y){if(x>y)x=y;}
int cnt[256],nxt[256],m,n,t_case;
char s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s",s+1);
		n=strlen(s+1);
		if(n==1){
			putchar(s[1]),putchar(10);
			continue;
		}
		for(ri i=1;i<=26;++i)cnt[i]=nxt[i]=0;
		for(ri i=1;i<=n;++i)++cnt[s[i]-'a'+1];
		ri pos=-1,tp=0;
		bool flag=false;
		for(ri i=1,lst=0;i<=26;++i)
			if(cnt[i]>0){
				if(cnt[i]==1&&!flag){
					cnt[i]=0;
					flag=true;
					putchar(i+'a'-1);
					continue;
				}
				++tp;
				if(pos==-1){
					lst=pos=i;
				}
				else{
					nxt[lst]=i;
					lst=i;
				}
			}
		if(flag){
			ri tmp=pos;
			while(tmp){
				if(!cnt[tmp]){
					tmp=nxt[tmp];
					continue;
				}
				putchar(tmp+'a'-1);
				--cnt[tmp];
			}
		}
		else if(tp==1){
			while(cnt[pos]--)putchar(pos+'a'-1);
		}
		else if(cnt[pos]>n-cnt[pos]+2){
			if(tp==2){
				putchar(pos+'a'-1);
				--cnt[pos];
				while(cnt[nxt[pos]]--)putchar(nxt[pos]+'a'-1);
				while(cnt[pos]--)putchar(pos+'a'-1);
			}
			else{
				putchar(pos+'a'-1);
				--cnt[pos];
				putchar(nxt[pos]+'a'-1);
				--cnt[nxt[pos]];
				while(cnt[pos]--)putchar(pos+'a'-1);
				putchar(nxt[nxt[pos]]+'a'-1);
				--cnt[nxt[nxt[pos]]];
				ri tmp=nxt[pos];
				while(tmp){
					if(!cnt[tmp]){
						tmp=nxt[tmp];
						continue;
					}
					putchar(tmp+'a'-1);
					--cnt[tmp];
				}
			}
		}
		else{
			putchar(pos+'a'-1);
			--cnt[pos];
			ri tmp=nxt[pos];
			while(cnt[pos]--){
				putchar(pos+'a'-1);
				while(tmp){
					if(!cnt[tmp]){
						tmp=nxt[tmp];
						continue;
					}
					putchar(tmp+'a'-1);
					--cnt[tmp];
					break;
				}
			}
			while(tmp){
				if(!cnt[tmp]){
					tmp=nxt[tmp];
					continue;
				}
				putchar(tmp+'a'-1);
				--cnt[tmp];
			}
		}
		putchar(10);
		for(ri i=1;i<=n;++i)s[i]=0;
	}
}