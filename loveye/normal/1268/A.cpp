#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

typedef long long ll;
#define fr(i,l,r) for(int i = (l);i <= (r);++i)
#define rf(i,l,r) for(int i = (l);i >= (r);--i)
#define fo(i,l,r) for(int i = (l);i < (r);++i)
#define foredge(i,u,v) for(int i = fir[u],v;v = to[i],i;i = nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N = 2e5 + 5;
int n,k,stk[N],top;
char a[N],b[N];
int main() {
	ios::sync_with_stdio(0);
	cin >> n >> k >> a;
	fo(i,0,k) b[i] = a[i];
	int ok = 1;
	fo(i,k,n) if(b[i % k] > a[i]) break;
	else if(b[i % k] < a[i]) {
		ok = 0; break;
	}
	if(!ok) {
		rf(i,k-1,0) if(a[i] != '9') {
			fr(j,i+1,k-1) b[j] = '0';
			b[i] = a[i] + 1; break;
		}
	}
	cout << n << endl;
	fo(i,k,n) b[i] = b[i % k];
	cout << b << endl;
	return 0;
}