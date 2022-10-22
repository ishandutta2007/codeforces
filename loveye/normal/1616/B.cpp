#include<cstdio>
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

const int N=1e5+5;
int n;
char s[N];
void print(int i) {
	s[i+1]='\0';
	cout<<s+1;
	reverse(s+1,s+i+1);
	cout<<s+1;
	cout<<endl;
}
int main() {
	ios::sync_with_stdio(0);
	int t; cin>>t;
	while(t--) {
		cin>>n>>s+1;
		if(s[1]==s[2]) print(1);
		else {
			int p=1;
			while(p<n&&s[p]>=s[p+1]) ++p;
			print(p);
		}
	}
	return 0;
}