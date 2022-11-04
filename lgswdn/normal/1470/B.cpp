#include<bits/stdc++.h>
#define int long long
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e6+9,mod=1e9+7;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int t,n,q,a[N],pr[N],cnt;
bool vst[N];

void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vst[i]) pr[++cnt]=i;
		for(int j=1;j<=cnt&&i*pr[j]<=n;j++){
			vst[i*pr[j]]=1;
			if(i%pr[j]==0) break;
		}
	}
}

signed main() {
	t=read();
	sieve(1000000);
	while(t--) {
		n=read();
		rep(i,1,n) {
			a[i]=read();
			for(int j=1;j<=cnt&&pr[j]*pr[j]<=a[i];j++) {
				while(a[i]%(pr[j]*pr[j])==0) a[i]/=(pr[j]*pr[j]);
			}
		}
		sort(a+1,a+n+1); a[n+1]=0;
		int mx=0,sum=0,cnt=0,cnt1=0;
		rep(i,1,n+1) {
			if(a[i]!=a[i-1]) {
				mx=max(mx,cnt);
				if(cnt%2==0) sum+=cnt;
				if(a[i-1]==1&&cnt%2!=0) cnt1=cnt;
				cnt=1;
			} else cnt++;
		}
		q=read();
		while(q--) {
			int w=read();
			if(w==0) printf("%lld\n",mx);
			else printf("%lld\n",max(mx,sum+cnt1));
		}
	}
	return 0;
}