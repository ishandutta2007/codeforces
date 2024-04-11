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

const int N = 3005;
int n,a[N],cnt[2];
int main() {
	ios::sync_with_stdio(0);
	int T;cin >> T;
	while(T--) {
		cin >> n;
		cnt[0] = cnt[1] = 0;
		for(int i = 1;i <= n;++i)
			cin >> a[i],++cnt[a[i]];
		if(cnt[0] >= cnt[1]) {
			cout << cnt[0] << endl;
			for(int i = 1;i <= cnt[0];++i)
				cout << 0 << ' ';
			cout << endl;
		}
		else {
			cnt[1] &= ~1;
			cout << cnt[1] << endl;
			for(int i = 1;i <= cnt[1];++i)
				cout << 1 << ' ';
			cout << endl;
		}
	}
	return 0;
}