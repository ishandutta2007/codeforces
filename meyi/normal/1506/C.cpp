#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10;
int t_case;
char s[maxn],t[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s%s",s+1,t+1);
		ri ans=0,sl=strlen(s+1),tl=strlen(t+1);
		if(sl<tl)swap(s,t),swap(sl,tl);
		for(ri i=1;i<=sl;++i)
			for(ri j=1;j<=tl;++j)
				for(ri k=1;j+k-1<=tl;++k)
					if(s[i+k-1]==t[j+k-1])
						ans=max(ans,k);
					else break;
		printf("%d\n",sl+tl-ans*2);
	}
	return 0;
}