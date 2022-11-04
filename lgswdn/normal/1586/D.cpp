#include<bits/stdc++.h>
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

const int N=109;
int n,p[N];

int query(vi &a) {
	printf("? "); for(auto x:a) printf("%d ",x); puts("");
	fflush(stdout);
	return read();
}

int main() {
	n=read();
	rep(i,1,n-1) {
		vi a;
		rep(j,1,n-1) a.emplace_back(n); a.emplace_back(n-i);
		int res=query(a);
		if(!res) {p[n]=i; break;}
	} if(!p[n]) p[n]=n;
	rep(i,1,n) if(i!=p[n]) {
		vi a;
		rep(j,1,n-1) a.emplace_back(p[n]); a.emplace_back(i);
		int res=query(a);
		p[res]=i;
	}
	printf("! "); rep(i,1,n) printf("%d ",p[i]); puts(""); fflush(stdout);
	return 0;
}