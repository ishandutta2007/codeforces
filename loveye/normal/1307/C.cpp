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

const int N=1e5+5;
char s[N];
int n;
int main() {
	cin>>s+1;
	n=strlen(s+1);
	ll ans=0;
	fo(c1,0,26) fo(c2,0,26) if(c1!=c2) {
		int s1=0;
		ll res=0;
		fr(i,1,n) {
			if(s[i]-'a'==c1) ++s1;
			else if(s[i]-'a'==c2) res+=s1;
		}
		ans=max(ans,res);
	}
	fo(c1,0,26) {
		int s1=0; ll res=0;
		fr(i,1,n) if(s[i]-'a'==c1) res+=s1,++s1;
		ans=max(ans,res);
		ans=max(ans,s1+0ll);
	}
	cout<<ans<<endl;
	return 0;
}