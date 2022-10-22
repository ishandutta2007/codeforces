#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int m,n,t_case;
char a[maxn],b[maxn],s[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		int cnt=0;
		for(ri i=1;i<=n;++i)
			if(s[i]=='1')
				++cnt;
		if((n&1)||(cnt&1)){
			puts("NO");
			continue;
		}
		bool flag1=false,flag2=false;
		ri p1=0,p2=0;
		cnt>>=1;
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		for(ri i=1;i<=n;++i){
			if(s[i]=='1'){
				if(cnt)--cnt,a[i]=b[i]='(',++p1,++p2;
				else a[i]=b[i]=')',--p1,--p2;
			}
			else{
				if(flag1)a[i]='(',b[i]=')',++p1,--p2;
				else a[i]=')',b[i]='(',--p1,++p2;
				flag1^=1;
			}
			if(p1<0||p2<0){flag2=true;break;}
		}
		if(flag2||p1||p2)puts("NO");
		else printf("YES\n%s\n%s\n",a+1,b+1);
	}
	return 0;
}