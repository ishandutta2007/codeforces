#include<bits/stdc++.h>
using namespace std;

int read();
#define LL long long
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define ci const int &
#define cl const LL &
#define I inline void
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2e5 + 5;
int n;
LL a[N],k,x;
vector<LL> v;
int main() {
	cin >> n >> k >> x;
	fr(i,1,n) cin >> a[i];
	sort(a+1,a+n+1);
	fo(i,1,n) if(a[i+1] - a[i] > x) v.push_back((a[i+1]-a[i]-1) / x);
	sort(v.begin(),v.end(),greater<LL>());
	while(v.size() && v.back() <= k) k -= v.back(),v.pop_back();
	cout << v.size()+1 << endl;
	return 0;
}