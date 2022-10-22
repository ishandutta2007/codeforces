#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e6+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
int a,b,c,cnt0,cnt1,d,len;
char s[maxn];
signed main(){
	scanf("%d%d%d%d",&a,&b,&c,&d);
	cnt0=sqrt(a<<1)+1,cnt1=sqrt(d<<1)+1;
	if(!b&&!c)--(cnt1==1?cnt1:cnt0);
	if(cnt0*(cnt0-1)/2!=a||cnt1*(cnt1-1)/2!=d||cnt0*cnt1!=b+c)return puts("Impossible"),0;
	for(ri i=cnt0+cnt1;i;--i){
		if(b>=cnt1)s[len++]=48,b-=cnt1;
		else s[len++]=49,--cnt1;
	}
	puts(s);
	return 0;
}