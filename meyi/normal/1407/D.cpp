#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=3e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
int f[maxn],h[maxn],n,st1[maxn],st2[maxn],tp1,tp2;
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i)scanf("%d",h+i);
	f[0]=n;
	st1[tp1=1]=st2[tp2=1]=1;
	for(ri i=2;i<=n;++i){
		f[i]=f[i-1]+1;
		while(tp1&&h[st1[tp1]]>=h[i]){
			if(h[st1[tp1]]!=h[i])ckmin(f[i],f[st1[tp1-1]]+1);
			--tp1;
		}
		st1[++tp1]=i;
		while(tp2&&h[st2[tp2]]<=h[i]){
			if(h[st2[tp2]]!=h[i])ckmin(f[i],f[st2[tp2-1]]+1);
			--tp2;
		}
		st2[++tp2]=i;
	}
	printf("%d",f[n]);
	return 0;
}