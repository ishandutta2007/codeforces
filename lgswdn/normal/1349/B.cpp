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

const int N=1e5+9;
int T,n,k,a[N];

signed main() {
	T=read();
	while(T--) {
		n=read(), k=read();
		rep(i,1,n) a[i]=read();
		bool flag=0;
		rep(i,1,n) if(a[i]==k) flag=1;
		if(!flag) {puts("no"); continue;}
		if(n==1) {puts("yes"); continue;}
		flag=0;
		rep(i,2,n) if(a[i]>=k&&a[i-1]>=k) flag=1;
		if(flag) {puts("yes"); continue;}
		flag=0;
		rep(i,2,n-1) if(a[i-1]>=k&&a[i+1]>=k) flag=1;
		if(flag) {puts("yes"); continue;}
		puts("no");
	}
	return 0;
}