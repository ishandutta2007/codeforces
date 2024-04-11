#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=110;
int m,n,t_case;
char a[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%d%s",&n,&m,a+1);
		ri l,r;
		for(ri i=1;i<=n;++i)
			if(a[i]=='*'){
				l=i;
				break;
			}
		for(ri i=n;i;--i)
			if(a[i]=='*'){
				r=i;
				break;
			}
		if(l==r)puts("1");
		else if(r-l>m){
			ri ans=2,tmp=l;
			while(r-tmp>m){
				for(ri i=tmp+m;i>tmp;--i)
					if(a[i]=='*'){
						tmp=i;
						++ans;
						break;
					}
			}
			printf("%d\n",ans);
		}
		else puts("2");
	}
	return 0;
}