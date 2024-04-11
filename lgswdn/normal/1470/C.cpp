#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
using namespace std;
const int N=1e5+9;

inline long long read() {
	long long res=0, w=1; char c=getchar();
	while(!isdigit(c)) {if(c=='-') w=-1; c=getchar();}
	while(isdigit(c)) {res=res*10+c-48; c=getchar();}
	return res*w;
}

int n,k,bs;

int qry(int x) {
	printf("? %d\n",(x-1)%n+1); fflush(stdout);
	return read();
}

int main() {
	n=read(), k=read();
	bs=(n>900?400:1);
	rep(i,1,bs) qry(1);
	int l=0,r=0;
	for(int i=1;i<=n;i+=bs) {
		int p=qry(i); if(p==k) continue;
		if(p>k) r=i; else l=i;
	} r+=n*(l>r);
	while(l<=r) {
		int mid=(l+r)/2, p=qry(mid);
		if(p==k) {
			printf("! %d",(mid-1)%n+1);
			return 0;
		}
		if(p>k) r=mid-1;
		else l=mid+1;
	}
	throw "shit";
	return 0;
}