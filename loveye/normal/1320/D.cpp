#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5,base=131,MOD=1e9+7;
int n;
char s[N];
int pos[N],tot;
ll hsh[N],pw[N];
ll gethsh(int l,int r) {
	return ((hsh[r]-hsh[l-1]*pw[r-l+1])%MOD+MOD)%MOD;
}
int chk(int l1,int r1,int l2,int r2) {
	int p1=lower_bound(pos+1,pos+tot+1,l1)-pos;
	int q1=upper_bound(pos+1,pos+tot+1,r1)-pos;
	int p2=lower_bound(pos+1,pos+tot+1,l2)-pos;
	int q2=upper_bound(pos+1,pos+tot+1,r2)-pos;
	if(q1-p1^q2-p2) return 0;
	if(q1==p1) return 1;
	if((pos[p1]-l1&1)^(pos[p2]-l2&1)) return 0;
	if(q1-p1==1) return 1;
	return gethsh(p1,q1-2)==gethsh(p2,q2-2);
}
int main() {
	scanf("%d%s",&n,s+1);
	fr(i,1,n) if(s[i]=='0') pos[++tot]=i;
	pw[0]=1;
	fr(i,1,tot-1) {
		hsh[i]=(hsh[i-1]*base+(pos[i+1]-pos[i]&1))%MOD;
		pw[i]=pw[i-1]*base%MOD;
	}
	int q; scanf("%d",&q);
	while(q--) {
		static int l,r,len;
		scanf("%d%d%d",&l,&r,&len);
		puts(chk(l,l+len-1,r,r+len-1)?"Yes":"No");
	}
	return 0;
}