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
typedef bitset<509> bset;
typedef pair<bset,bset> v2;

long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48, c=getchar();}
	return res*w;
}

int T,n,a,b;

signed main() {
	T=read();
	while(T--) {
		n=read(), a=read(), b=read();
		int r=1;
		if(b==1) puts("YES");
		else if(n%b==1) puts("YES");
		else {
			if(a==1) puts("NO");
			else {
				bool flag=0;
				while(r<=n) {
					if(n%b==r%b) {
						flag=1;
						puts("YES");
						break;
					}
					r*=a;
				}
				if(!flag) puts("NO");
			}
		}
	}
	return 0;
}