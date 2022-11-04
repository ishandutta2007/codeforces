#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e4+9,mod=1000000007;

int n,k,a[N],c[N][36],p[N];

struct trie {
	struct node {
		int ch[2],mn,mx,sz;
	}t[N*36];
	int tot;
	void insert(int i,int val,int u=1) {
		t[u].sz++; tot=max(tot,1ll);
		for(int h=33;h>=0;h--) {
			bool pp=val&(1ll<<h);
			if(!t[u].ch[pp]) t[u].ch[pp]=++tot,t[t[u].ch[pp]].mn=i;
			u=t[u].ch[pp]; t[u].mx=i; t[u].sz++;
		}
	}
	int cal(int val,int l,int r) {
		if(l==0) return 0;
		int ans=0;
		for(int h=33;h>=0;h--) {
			bool pp=val&(1ll<<h);
			if(pp==0) ans+=(1ll<<h)*(c[r][h]-c[l-1][h]);
			else ans+=(1ll<<h)*(r-l+1-c[r][h]+c[l-1][h]);
		}
		return ans;
	}
	int kth(int k) {
		int cnt=0,kt=0,ans=0;
		for(int h=33;h>=0;h--) {
			cnt=0;
			for(int i=1;i<=n;i++) {
				bool pp=a[i]&(1ll<<h); pp^=1;
				cnt+=t[t[p[i]].ch[pp]].sz;
			}
			bool op=1;
			if(k<=cnt) kt|=(1ll<<h);
			else k-=cnt,op=0;
			for(int i=1;i<=n;i++) {
				bool pp=a[i]&(1ll<<h); pp^=op;
				p[i]=t[p[i]].ch[pp];
			}
		}
		for(int i=1;i<=n;i++) {
			int u=1;
			for(int h=33;h>=0;h--) {
				bool pp=((a[i]^kt)>>h)&1;
				if((kt&(1ll<<h))==0&&t[u].ch[pp^1])
					ans+=cal(a[i],t[t[u].ch[pp^1]].mn,t[t[u].ch[pp^1]].mx);
				u=t[u].ch[pp];
			}
		}
		return (ans+k*kt)/2;
	}
}tt;

signed main() {
	scanf("%lld%lld",&n,&k); k<<=1;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) for(int h=0;h<=33;h++)
		if(a[i]&(1ll<<h)) c[i][h]+=c[i-1][h]+1;
		else c[i][h]=c[i-1][h];
	for(int i=1;i<=n;i++) tt.insert(i,a[i]),p[i]=1;
	printf("%lld",tt.kth(k)%mod);
	return 0;
}