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

const int N=2e5+5;
int n;
char s[N];
int main() {
	cin>>n>>s+1;
	fr(i,1,n) if(s[i]==')') {
		s[n+1]=')';
		int res=0;
		fr(j,1,n+1) {
			if(j==i) continue;
			if(s[j]==')') {
				--res;
				if(res<0) break;
			} else ++res;
		}
		if(res==0) return puts("Yes"),0;
		break;
	}
	rf(i,n,1) if(s[i]=='(') {
		s[0]='(';
		int res=0;
		fr(j,0,n) {
			if(j==i) continue;
			if(s[j]==')') {
				--res;
				if(res<0) break;
			} else ++res;
		}
		if(res==0) return puts("Yes"),0;
		break;
	}
	puts("No");
	return 0;
}

const int S=1<<21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}