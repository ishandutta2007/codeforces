#include<bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define rep2(i,a,b) for(int i=(a);i<=(b);i+=2)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define per2(i,a,b) for(int i=(a);i>=(b);i-=2)
using namespace std;
const int N=1e6+9;
typedef pair<int,int> pii;
typedef vector<int> vi;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int T,n,s[N],ky;
vi ans;

void mdf(int x) {if(s[x]!=s[x+1]||s[x]!=s[x+2]) ans.push_back(x),s[x]=s[x+1]=s[x+2]=(s[x]^s[x+1]^s[x+2]);}

signed main() {
	T=read();
	while(T--) {
		n=read(); int cnt=0; ans.clear(); ky=0;
		rep(i,1,n) s[i]=read(), cnt+=s[i];
		if(cnt%2!=0) {puts("NO"); continue;}
		cnt=0;
		rep(i,1,n) cnt+=s[i], ky=(((!(cnt%2))&&(i%2))?i:ky);
		if(!ky) {puts("NO"); continue;}
		rep2(i,1,ky-1) mdf(i); per2(i,ky-4,1) mdf(i);
		rep2(i,ky+(n%2==0),n-2) mdf(i); per2(i,n-4,ky+(n%2==0)) mdf(i);
		puts("YES");
		int sz=ans.size(); printf("%lld\n",sz);
		for(int x:ans) printf("%lld ",x); if(sz) puts("");
	}
	return 0;
}