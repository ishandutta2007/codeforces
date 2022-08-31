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

VI v[200];
char s[200],a[10][200];
int main() {
	scanf("%s",s);
	rep(i,0,27) {
		v[s[i]-'A'].pb(i);
	}
	rep(i,0,26) if (SZ(v[i])==2) {
		if (v[i][0]+1==v[i][1]) {
			puts("Impossible");
			return 0;
		} else {
			int l=v[i][0],r=v[i][1];
			int x=min((r-l+1)/2,12),y=0;
//			printf("%d %d\n",x,y);
			rep(i,0,l) {
				if (y==0) {
					if (x<12) x++;
					else y++;
				} else {
					if (x>0) x--;
					else y--;
				}
			}
			rep(i,0,27) {
				if (i==r) continue;
				if (y==1) {
					if (x<12) x++;
					else y--;
				} else {
					if (x>0) x--;
					else y++;
				}
				a[y][x]=s[i];
			}
			printf("%s\n",a[0]);
			printf("%s\n",a[1]);
		}
	}
}