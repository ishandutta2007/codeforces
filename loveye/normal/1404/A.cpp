#include<cstdio>
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

const int N=3e5+5;
int n,k;
char s[N];
int main() {
	int t;
	cin>>t;
	while(t--) {
		cin>>n>>k;
		cin>>s+1;
		int ok=1;
		int cnt0=0,cnt1=0;
		fr(i,1,k) {
			int ok0=0,ok1=0;
			for(int j=i;j<=n;j+=k) {
				ok0|=s[j]=='0';
				ok1|=s[j]=='1';
			}
			if(ok0&&ok1) {
				ok=0; break;
			} else if(ok0||ok1) {
				if(ok0) cnt0++;
				else cnt1++;
			}
		}
		if(!ok||abs(cnt0-cnt1)>k-cnt0-cnt1) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}

const int S = 1 << 21;
char p0[S],*p1,*p2;
#define getchar() (p2==p1&&(p2=(p1=p0)+fread(p0,1,S,stdin))==p1?EOF:*p1++)
inline int read() {
	static int x,c,f;x=0;f=1;
	do c=getchar(),c=='-'&&(f=-1); while(!isdigit(c));
	do x=x*10+(c&15),c=getchar(); while(isdigit(c));
	return x*f;
}