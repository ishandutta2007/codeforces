#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define jmp(i,a,b,c) for(int i=(a);i<=(b);i+=(c))
#define pmj(i,a,b,c) for(int i=(a);i>=(b);i-=(c))
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();} 
	return res*w;
}

const int N=209;
int T,cnt[N];

signed main() {
	T=read();
	while(T--) {
		int n=read();
		rep(i,0,200) cnt[i]=0;
		rep(i,1,n) cnt[abs(read())]++;
		int ans=0;
		rep(i,0,200) {
			if(i==0) ans+=min(1ll,cnt[i]);
			else ans+=min(2ll,cnt[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}