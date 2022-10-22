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
#define all(v) v.begin(),v.end()

const int N=1e5+5;
int n,m;
vector<long double> b[N];
long double a[N],c[N],s[N];
int d[N],pos[N];
vector<int> zero,one;
int chk(int l,int r) {
	auto it=lower_bound(all(zero),r);
	if(it!=zero.end()&&*it==r) return 0;
	return it==lower_bound(all(zero),l);
}
int main() {
	for(int t=read();t--;) {
		n=read(),m=read();
		//cout<<n<<m<<endl;
		fr(i,1,n) a[i]=read();
		sort(a+1,a+n+1);
		fr(i,1,n) d[i]=1; d[n+1]=d[n+2]=0;
		fr(i,1,m) {
			b[i].resize(read());
			generate(all(b[i]),read);
			s[i]=accumulate(all(b[i]),0.l);
			c[i]=s[i]/b[i].size();
			pos[i]=lower_bound(a+1,a+n+1,c[i])-a;
			--d[pos[i]];
		}
		rf(i,n,1) d[i]+=d[i+1];
		if(*min_element(d+1,d+n+2)<-1) {
			fr(i,1,m) fo(j,0,b[i].size()) putchar('0');
			continue;
		}
		zero.clear(); one.clear();
		fr(i,1,n+1) {
			if(d[i]==0) zero.push_back(i);
			if(d[i]==-1) one.push_back(i);
		}
		fr(i,1,m) fo(j,0,b[i].size()) {
			long double nc=(s[i]-b[i][j])/(b[i].size()-1);
			int np=lower_bound(a+1,a+n+1,nc)-a;
			if(np<=pos[i]) {
				putchar('0'|(one.empty()||(np+1<=one[0]&&one.back()<=pos[i])));
			} else {
				putchar('0'|(one.empty()&&chk(pos[i]+1,np)));
			}
		}
		puts("");
	}
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}