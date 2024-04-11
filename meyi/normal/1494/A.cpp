#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=60;
struct node{
	char c;
	int v;
	inline bool operator<(const node &k)const{
		return v<k.v;
	}
}cnt[3];
int n,t;
char s[maxn];
int main(){
	scanf("%d",&t);
	while(t--){
		memset(s,0,sizeof s);
		scanf("%s",s+1);
		memset(cnt,0,sizeof cnt);
		for(ri i=0;i<3;++i)cnt[i].c=i+'A';
		for(ri i=1;s[i];++i)++cnt[s[i]-'A'].v;
		sort(cnt+0,cnt+3);
		if(cnt[0].v+cnt[1].v==cnt[2].v){
			n=0;
			bool flag=false;
			ri tmp=(s[1]==cnt[2].c?1:-1);
			for(ri i=1;!flag&&s[i];++i)
				for(ri j=0;j<3;++j)
					if(s[i]==cnt[j].c){
						n+=(j<2?-tmp:tmp);
						if(n<0){
							flag=true;
							break;
						}
					}
			puts(flag?"NO":"YES");
		}
		else puts("NO");
	}
	return 0;
}