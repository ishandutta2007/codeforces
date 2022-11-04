#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

signed main() {
	int T=read();
	while(T--) {
		int n=read(), ans=0, lst=0;
		rep(i,1,n) {
			int x=read();
			if(x<lst) ans+=lst-x;
			lst=x;
		}
		printf("%lld\n",ans);
	}
	return 0;
}