#include<cstdio>
#include<numeric>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=1e6+5;
int n,m;
char s[N];
int f[N],ans[N];
int main() {
	int T=read();
	while(T--) {
		n=read(),m=read();
		scanf("%s",s);
		int sum=0;
		fo(i,0,n*m) ans[i]=n+m-(n-1-i/m)-max(0,m-1-i);
		fo(i,0,n*m) {
			sum+=s[i]-'0';
			if(i>=m) sum-=s[i-m]-'0';
			if(!sum) ++f[i];
		}
		fo(i,m,n*m) f[i]+=f[i-m];
		fo(i,0,n*m) ans[i]-=f[i],f[i]=0;
		fo(st,0,m) {
			sum=0;
			for(int i=st;i<n*m;i+=m) {
				sum+=s[i]-'0';
				if(!sum) {
					++f[i];
					if(i+m<n*m) --f[i+m];
				}
			}
		}
		fo(i,1,n*m) f[i]+=f[i-1];
		fo(i,0,n*m) ans[i]-=f[i],f[i]=0;
		fo(i,0,n*m) printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}

inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}