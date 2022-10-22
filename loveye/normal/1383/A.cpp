#include<cstdio>
#include<bitset>
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

const int N=1e5+5;
int t,n;
char a[N],b[N];
int f[N],siz[N]; int getf(int x) {return f[x]==x?x:f[x]=getf(f[x]);}
void merge(int u,int v) {
	u=getf(u),v=getf(v);
	if(u!=v) f[u]=v;
}
int main() {
	cin>>t;
	while(t--) {
		cin>>n>>a+1>>b+1;
		int ok=1;
		fr(i,1,20) f[i]=i,siz[i]=0;
		fr(i,1,n) if(a[i]>b[i]) {
			ok=0; break;
		} else merge(a[i]-'a'+1,b[i]-'a'+1);
		if(!ok) {
			cout<<-1<<endl;
			continue;
		}
		fr(i,1,20) ++siz[getf(i)];
		int ans=0;
		fr(i,1,20) if(f[i]==i) ans+=siz[i]-1;
		cout<<ans<<endl;
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2 == p1 && (p2 = (p1 = p0) + fread(p0,1,S,stdin)) == p1 ? EOF : *p1++)
inline int read() {
	static int x,c,f;x = 0;f = 1;
	do c = getchar(),c == '-' && (f = -1);while(!isdigit(c));
	do x = x * 10 + (c & 15),c = getchar();while(isdigit(c));
	return x * f;
}