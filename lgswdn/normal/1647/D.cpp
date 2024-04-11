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

bool prime(int x) {
	if(x==1) return 1;
	for(int y=2;y*y<=x;y++) if(x%y==0) return 0;
	return 1; 
}
pii check(int x) {
	for(int y=2;y*y<=x;y++) if(x%y==0) {
		int cc=0;
		while(x%y==0) x/=y,cc++;
		if(x==1) return pii(y,cc);
		else return pii(0,0);
	}
	if(prime(x)) return pii(x,1);
	return pii(0,0);
}

signed main() {
	int T=read();
	while(T--) {
		int x=read(), d=read(), s=x, p=0;
		while(s%d==0) s/=d, p++;
		if(p<=1) puts("NO");
		else {
			if(!prime(s)) puts("YES");
			else {
				pii c=check(d);
				if(!c.fi) puts(p>2?"YES":"NO");
				else if(c.fi!=s) {
					if(c.se==1) puts("NO");
					else puts(p>=3?"YES":"NO");
				} else {
					if(c.se==1) puts("NO");
					else if(c.se==2) puts(p>=4?"YES":"NO");
					else puts(p>=3?"YES":"NO");
				}
			}
		}
	}
	return 0;
}