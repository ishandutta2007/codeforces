#include<bits/stdc++.h>
#define rep(i,a,b) for(register int i=(a);i<=(b);i++)
using namespace std;
const int N=10009;

inline int read() {
    register int x=0, f=1; register char c=getchar();
    while(c<'0'||c>'9') {if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') {x=(x<<3)+(x<<1)+c-48,c=getchar();}
    return x*f;
}

int T,n,a[N],sum,avg,ans;

signed main() {
	T=read();
	while(T--) {
		n=read(); sum=ans=0;
		rep(i,1,n) a[i]=read(), sum+=a[i];
		if(sum%n) {puts("-1"); continue;}
		avg=sum/n;
		ans=(n-1)*2;
		rep(i,2,n) if(a[i]%i!=0) ans++;
		printf("%d\n",ans);
		rep(i,2,n) {
			if(a[i]%i) printf("%d %d %d\n",1,i,i-a[i]%i), a[1]-=(i-a[i]%i), a[i]+=(i-a[i]%i);
			printf("%d %d %d\n",i,1,a[i]/i), a[1]+=a[i], a[i]-=a[i];
		}
		rep(i,2,n) printf("%d %d %d\n",1,i,a[1]/n);
	}
	return 0;
}