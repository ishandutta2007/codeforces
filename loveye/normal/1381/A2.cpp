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
int T,n;
char s[N],t[N];
vector<int> ans;
int l,r,fl;
int getfront() {return fl?s[r]^1:s[l];}
int getback() {return fl?s[l]^1:s[r];}
void work(int i) {
	if(i==1) {
		if(fl) s[r]^=1;
		else s[l]^=1;
	} else fl^=1;
}
int main() {
	cin>>T;
	while(T--) {
		cin>>n;
		cin>>s+1>>t+1;
		l=1,r=n,fl=0;
		rf(i,n,1) {
			if(getback()!=t[i]) {
				if((getfront()^t[i])==1) ans.push_back(i),work(i);
				else ans.push_back(1),ans.push_back(i),work(1),work(i);
			}
			if(fl) ++l;
			else --r;
		}
		cout<<ans.size()<<' ';
		for(auto x:ans) cout<<x<<' ';
		cout<<endl;
		ans.clear();
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