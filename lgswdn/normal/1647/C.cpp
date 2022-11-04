#include<bits/stdc++.h>
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

const int N=109;
int n,m,a[N][N];
char s[N][N];

struct answer {
	int a,b,c,d;
	answer(int _a,int _b,int _c,int _d) {a=_a,b=_b,c=_c,d=_d;}
};
vector<answer>ans;

signed main() {
	int T=read();
	while(T--) {
		n=read(), m=read();
		rep(i,1,n) scanf("%s",s[i]+1);
		if(s[1][1]=='1') {
			puts("-1");
			continue;
		}
		ans.clear();
		rep(i,1,n) rep(j,1,m) a[i][j]=s[i][j]-'0';
		per(i,n,1) per(j,m,1) if(a[i][j]) {
			if(j>1) ans.emplace_back(answer(i,j-1,i,j));
			else if(i>1) ans.emplace_back(answer(i-1,j,i,j));
		}
		printf("%d\n",(int)ans.size());
		for(auto x:ans) printf("%d %d %d %d\n",x.a,x.b,x.c,x.d);
	}
	return 0;
}