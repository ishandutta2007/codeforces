#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1<<18|5;
int k,q;
char s[MAXN];
int f[MAXN];
inline void upd(int x){
	if(x>=(1<<k-1)){
		if(s[x]=='?') f[x]=2;
		else f[x]=1;
	}
	else if(s[x]=='?') f[x]=f[x<<1]+f[x<<1|1];
	else if(s[x]=='1') f[x]=f[x<<1];
	else f[x]=f[x<<1|1];
	//printf("x %d f %d\n",x,f[x]);
}
int main(){
	scanf("%d",&k);
	scanf("%s",s+1);
	reverse(s+1,s+(1<<k));
	for(int i=(1<<k)-1; i; i--)
		upd(i);
	scanf("%d",&q);
	while(q--){
		int p;
		char c[5];
		scanf("%d%s",&p,c);
		p=(1<<k)-p;
		s[p]=*c;
		while(p){
			upd(p);
			p>>=1;
		}
		printf("%d\n",f[1]);
	}
	return 0;
}