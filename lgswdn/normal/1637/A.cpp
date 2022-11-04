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

const int N=1e4+9;
int n,T;
vi a,b;

signed main() {
	T=read();
	while(T--) {
		int n=read();
		a.resize(n+1), b.resize(n+1);
		rep(i,1,n) a[i]=b[i]=read();
		sort(b.begin(),b.end());
		if(a==b) puts("NO");
		else puts("YES");
	}
	return 0;
}