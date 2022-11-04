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

const int N=4e5+9;
int T,n,c[N];

signed main() {
	T=read();
	while(T--) {
		n=read();
		rep(i,1,n) c[i]=0;
		rep(i,1,n) c[read()]++;
		int val=-1;
		rep(i,1,n) if(c[i]>=3) val=i;
		printf("%lld\n",val);
	}
	return 0;
}