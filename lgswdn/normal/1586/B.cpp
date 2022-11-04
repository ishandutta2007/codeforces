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

const int N=1e6+9;
int T,n,m;
bool bl[N];

int main() {
	T=read();
	while(T--) {
		n=read(), m=read();
		rep(i,1,n) bl[i]=0;
		rep(i,1,m) {
			int a=read(), b=read(), c=read();
			bl[b]=1;
		}
		int rt=0;
		rep(i,1,n) if(!bl[i]) rt=i;
		rep(i,1,n) {
			if(i!=rt) printf("%d %d\n",rt,i);
		}
	}
	return 0;
}