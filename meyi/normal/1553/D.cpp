#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=4e5+10;
template<class T>inline void ckmax(int &x,const int &y){if(x<y)x=y;}
template<class T>inline void ckmin(int &x,const int &y){if(x>y)x=y;}
int a[maxn],m,n,t_case;
char s[maxn],t[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		ri j=m;
		for(ri i=n;i>0&&j>0;i-=2)
			if(s[i]==t[j])
				++i,--j;
		puts(j>0?"NO":"YES");
		for(ri i=1;i<=n;++i)s[i]=0;
		for(ri i=1;i<=m;++i)t[i]=0;
	}
}