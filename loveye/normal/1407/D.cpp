#include<bits/stdc++.h>
using namespace std;
const int MOD = 0;

const int S = 1 << 21;
char p0[S],*p1,*p2;
#ifndef ZXY
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
#endif
inline int read() {
	static int x,c;x = 0;
	do{c = getchar();}while(!isdigit(c));
	do{x = (x << 3) + (x << 1) + (c & 15);c = getchar();}while(isdigit(c));
	return x;
}

#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])

const int N = 3e5 + 5;
int n,a[N],st[N],top,st2[N],top2,dp[N];
int main() {
	scanf("%d",&n);
	for(int i = 1;i <= n;++i) scanf("%d",a+i);
	memset(dp,0x3f,sizeof dp);
	dp[n] = 0;
	st[++top] = n;
	st2[++top2] = n;
	for(int i = n-1;i >= 1;--i) {
		int ok1 = 1,ok2 = 1;
		while(top && a[st[top]] >= a[i]) {
			if(a[st[top]] == a[i]) ok1 = 0;
			dp[i] = min(dp[i],dp[st[top]]+1);
			--top;
		}
		if(top && ok1) dp[i] = min(dp[i],dp[st[top]]+1);
		st[++top] = i;
		while(top2 && a[st2[top2]] <= a[i]) {
			if(a[st2[top2]] == a[i]) ok2 = 0;
			dp[i] = min(dp[i],dp[st2[top2]]+1);
			--top2;
		}
		if(top2 && ok2) dp[i] = min(dp[i],dp[st2[top2]]+1);
		st2[++top2] = i;
	}
	printf("%d\n",dp[1]);
	return 0;
}