#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int t,d,cnt[256],mxc;
char s[N];
inline void add(int i) {
	++cnt[s[i]];
	if(cnt[s[i]] > cnt[mxc]) mxc = s[i];
}
inline void del(int i) {
	--cnt[s[i]];
}
int main() {
	scanf("%d",&t);
	while(t--) {
		int n,k,ans = 0;
		scanf("%d%d",&n,&k);
		scanf("%s",s+1);
		d = n/k;
		for(int i = 1;i <= (k+1>>1);++i) {
			int p = i,delta = k+1-i-i;mxc = 0;
			while(p <= n) add(p),add(p+delta),p += k;
			if(i == (k+1>>1) && (k & 1)) ans += d - (cnt[mxc]>>1);
			else ans += d*2 - cnt[mxc];
			p = i;
			while(p <= n) del(p),del(p+delta),p += k;
		}
		printf("%d\n",ans);
	}
	return 0;
}