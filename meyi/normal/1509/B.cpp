#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int cnt1,cnt2,n,t_case;
char s[maxn];
bool vis[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		cnt1=cnt2=0;
		for(ri i=1;i<=n;++i)
			if(s[i]=='T')
				++cnt1;
			else ++cnt2;
		if(cnt1!=cnt2*2){
			puts("NO");
			continue;
		}
		memset(vis,0,sizeof vis);
		bool flag=false;
		for(ri i=1,l=1;i<=n;++i)
			if(s[i]=='M'){
				while(l<=i&&s[l]!='T')++l;
				if(l>i){flag=true;break;}
				vis[l]=true,++l;
			}
		if(flag){
			puts("NO");
			continue;
		}
		for(ri i=n,r=n;i;--i)
			if(s[i]=='M'){
				while(r>=i&&s[r]!='T')--r;
				if(r<i||vis[r]){flag=true;break;}
				--r;
			}
		puts(flag?"NO":"YES");
	}
	return 0;
}