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

const int N = 1e6 + 5;
int q,n,m,a[N],b[N];
string s[N];
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> m;
	fr(i,1,n) {
		cin >> s[i];
		s[i].insert(s[i].begin(),'\0');
		//cout << s[i] << endl;
	}
	fo(i,1,m) {
		fo(j,1,n) if(s[j][i+1] == 'X' && s[j+1][i] == 'X') {
			a[i] = 1; break;
		}
	}
	fr(i,1,m) b[i] = b[i-1] + a[i];
	cin >> q;
	while(q--) {
		static int l,r;
		cin >> l >> r;
		cout << ((b[r-1]-b[l-1] > 0) ? "NO" : "YES") << endl;
	}
	return 0;
}