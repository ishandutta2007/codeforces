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

const int N=1e6+9;
int n,k,a[N],b[N],c[N];

void trans(int *a) {
	int mx=-1000000000;
	rep(i,1,n) mx=max(mx,a[i]);
	rep(i,1,n) a[i]=mx-a[i];
}
void print(int *a) {
	rep(i,1,n) printf("%lld ",a[i]);
	puts("");
}

signed main() {
	int T=read();
	while(T--) {
		n=read(), k=read();
		rep(i,1,n) a[i]=read();
		rep(i,1,n) b[i]=a[i];
		trans(b);
		rep(i,1,n) c[i]=b[i];
		trans(c);
		if(k%2==1) print(b);
		else print(c); 
	}
	return 0;
}