#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],m,n,pos,t_case;
char s[maxn],t[maxn];
int main(){
	scanf("%d",&t_case);
	while(t_case--){
		scanf("%d%s",&n,s+1);
		pos=1;
		while(pos<n&&s[pos+1]<=s[pos])++pos;
		for(ri i=1;i<=pos;++i)t[i]=s[i];
		for(ri i=pos;i;--i)t[2*pos-i+1]=s[i];
		s[2]=s[1],s[3]=0;
		t[2*pos+1]=0;
		if(strcmp(s+1,t+1)<0)puts(s+1);
		else puts(t+1);
	}
	return 0;
}