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

char op[10],x[30];
int cnt[22][1333333],n;
int main() {
	scanf("%d",&n);
	rep(i,0,n) {
		scanf("%s%s",op,x);
		if (op[0]=='+') {		
			int m=strlen(x),S=0;
			rep(i,0,m) {
				S=S*2+(x[i]-'0')%2;
			}
			cnt[m][S]++;
		} else if (op[0]=='-') {
			int m=strlen(x),S=0;
			rep(i,0,m) {
				S=S*2+(x[i]-'0')%2;
			}
			cnt[m][S]--;
		} else {
			int m=strlen(x),S=0;
			rep(i,0,m) {
				S=S*2+(x[i]-'0')%2;
			}
			int c=0;
			rep(i,0,19) {
				if (i>=m) c+=cnt[i][S];
				else if (S<(1<<m)) c+=cnt[i][S];
			}
			printf("%d\n",c);
		}
	}
}