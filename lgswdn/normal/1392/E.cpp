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

const int N=29;
int n,a[N][N];

int check(int x,int y,int s) {
	if(x<1||x>n||y<1||y>n) return 0; 
	else if(!a[x][y]) return 1;
	else if(!(s&a[x][y])) return 0;
	else return 2;
}

signed main() {
	n=read();
	rep(i,1,n) {rep(j,1,n) printf("%lld ",a[i][j]=(i%2?1ll<<(i+j-2):0)); puts("");}
	fflush(stdout);
	int q=read();
	while(q--) {
		int sum=read(), x=1, y=1; printf("%lld %lld\n",x,y);
		rep(i,1,2*n-2) {
			if(check(x+1,y,sum)>check(x,y+1,sum)) x++;
			else y++;
			printf("%lld %lld\n",x,y);
		}
		fflush(stdout);
	}
	return 0;
}