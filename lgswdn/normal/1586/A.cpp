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

const int N=1e5+9;
int T,n,a[N];

bool cp(int x) {
	for(int i=2;i*i<=x;i++) if(i!=x&&x%i==0) return 1;
	return 0;
}

signed main() {
	T=read();
	while(T--) {
		n=read();
		int sum=0;
		rep(i,1,n) a[i]=read();
		rep(i,1,n) sum+=a[i];
		if(cp(sum)) {
			printf("%d\n",n);
			rep(i,1,n) printf("%d ",i);
			puts("");
		} else {
			printf("%d\n",n-1);
			int pos=0;
			rep(i,1,n) if(a[i]%2==1) pos=i;
			rep(i,1,n) if(i!=pos) printf("%d ",i);
			puts("");
		}
	}
	return 0;
}