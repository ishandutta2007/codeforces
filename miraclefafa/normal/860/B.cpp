#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

const int N=70010;
int n,num[N][11][11];
char s[N][11];
map<int,int> st[11],cur[11];
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s",s[i]);
		rep(p,0,9) {
			int w=0;
			rep(q,p,9) {
				w=w*10+(s[i][q]-'0');
				auto it=cur[q-p].find(w);
				if (it==cur[q-p].end()) {
					cur[q-p][w]=i; st[q-p][w]=1;
				} else if (it->se!=i) {
					cur[q-p][w]=i; st[q-p][w]++;
				}
				num[i][p][q]=w;
			}
		}
	}
	rep(i,0,n) {
		rep(d,0,9) {
			rep(l,0,9-d) {
				int r=l+d;
				int c=num[i][l][r];
				if (st[d][c]==1) {
					rep(k,l,r+1) putchar(s[i][k]); puts("");
					goto ffff;
				}
			}
		}
		ffff:;
	}
}