#include<bits/stdc++.h>
#define int long long
using namespace std;
#define fi first
#define se second
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vp;
typedef unsigned long long ull;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

signed main() {
	int T=read();
	while(T--) {
		int n=read(), x=n/3;
		if(n%3==0) {
			rep(i,1,x) putchar('2'), putchar('1'); puts("");
		} else if(n%3==1) {
			putchar('1');
			rep(i,1,x) putchar('2'), putchar('1'); puts("");
		} else {
			putchar('2');
			rep(i,1,x) putchar('1'), putchar('2'); puts("");
		}
	}
	return 0;
}