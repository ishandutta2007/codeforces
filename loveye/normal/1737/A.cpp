#include<bits/stdc++.h>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(file) freopen(file".in","r",stdin)
#define fileout(file) freopen(file".out","w",stdout)

const int N=205;
int n,k;
char s[N];
int cnt[26];
int main() {
	int T; cin>>T;
	while(T--) {
		cin>>n>>k>>s+1;
		int len=strlen(s+1);
		memset(cnt,0,sizeof cnt);
		fr(i,1,len) ++cnt[s[i]-'a'];
		fr(kas,1,k) {
			int lim;
			fo(j,0,26) if(!cnt[j]) {
				lim=j; break;
			}
			lim=min(lim,n/k);
			fo(j,0,lim) --cnt[j];
			putchar('a'+lim);
		}
		puts("");
	}
	return 0;
}
int read() {
	static int x,c,f; x=0,f=1;
	do c=getchar(),(c=='-'&&(f=-1)); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}