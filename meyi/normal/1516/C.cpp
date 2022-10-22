#include<bits/stdc++.h>
using namespace std;
#define ri register int
#define DEBUG(k...) fprintf(stderr,k)
typedef long long ll;
template<class T>inline bool chmax(T &x,const T &y){return x<y?x=y,true:false;}
template<class T>inline bool chmin(T &x,const T &y){return x>y?x=y,true:false;}
const int maxn=2e5+10;
int a[maxn],g,m,n,s,t_case;
bool f[maxn];
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&n);
	for(ri i=1;i<=n;++i){
		scanf("%d",a+i);
		g=gcd(a[i],g);
	}
	for(ri i=1;i<=n;++i){
		a[i]/=g;
		s+=a[i];
	}
	if(s&1)puts("0");
	else{
		f[0]=true;
		for(ri i=1;i<=n;++i)
			for(ri j=s;j>=a[i];--j)
				f[j]|=f[j-a[i]];
		if(f[s>>1]){
			for(ri i=1;i<=n;++i)
				if(a[i]&1){
					printf("1\n%d",i);
					break;
				}
		}
		else puts("0");
	}
	return 0;
}