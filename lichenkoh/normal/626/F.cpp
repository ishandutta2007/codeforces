#include <bits/stdc++.h>
#include <assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define PB push_back
#define MP make_pair
#define MOD 1000000007LL
#define endl "\n"
const ll MAXFLY = 204;
const ll MAXK = 1004;
const ll MAXN = 204;
//const ll MAXFLY = 3;
//const ll MAXK = 4;
//const ll MAXN = 3;
ll f[2][MAXFLY][MAXK];
ll b[MAXN];
int main() {
	ios_base::sync_with_stdio(false);
	ll n,klim; cin >> n >> klim;
	for (ll i=0;i<n;i++) {
		cin >> b[i];
	}
	if (n==1) {
		cout << 1 << endl;
		return 0;
	}
	sort(b,b+n);
	for (ll fly=0;fly<MAXFLY;fly++) {
		for (ll k=0;k<MAXK;k++) {
			f[0][fly][k]=0;
		}
	}
	f[0][0][0]=1;
	f[0][1][0]=1;
	ll lasta=-1;
	for (ll x=0;x<n-1;x++) {
		ll c=x%2;
		ll a=(x+1)%2;
		lasta=a;
		for (ll fly=0;fly<MAXFLY;fly++) {
			for (ll k=0;k<MAXK;k++) {
				f[a][fly][k]=0;
			}
		}
		for (ll fly=0;fly<MAXFLY;fly++) {
			for (ll kin=0;kin<MAXK;kin++) {
				ll v=f[c][fly][kin];
				if (v==0) continue;
				ll dist = b[x+1]-b[x];
				ll know = kin + fly*dist;
				if (know >= MAXK) continue;
				{
					// self loop
					//if (x==0&&fly==1&&know==2) printf("A:%I64d. %I64d %I64d\n",v,fly,kin);
					f[a][fly][know] += v;
					f[a][fly][know] %= MOD;
				}
				{
					// absorb at x
					//if (x==0&&fly-1==1&&know==2) printf("B:%I64d\n",fly*v);
					if (fly-1>=0)
					{
						f[a][fly-1][know] += (fly*v)%MOD;
						f[a][fly-1][know] %= MOD;
					}
				}
				{
					// release at x
					//if (x==0&&fly+1==1&&know==2) printf("C:%I64d\n",v);
					f[a][fly+1][know] += v;
					f[a][fly+1][know] %= MOD;
				}
				{
					// absorb and release
					//if (x==0&&fly==1&&know==2) printf("D:%I64d\n",fly*v);
					f[a][fly][know] += fly*v;
					f[a][fly][know] %= MOD;
				}
			}
		}
		/*for (ll fly=0;fly<MAXFLY;fly++) {
			for (ll k=0;k<MAXK;k++) {
				printf("%I64d %I64d %I64d: %I64d\n",x,fly,k,f[a][fly][k]);
			}
		}*/
	}
	ll final=0;
	for (ll k=0;k<=klim;k++) {
		final = (final+f[lasta][0][k])%MOD;
	}
	cout << final << endl;
}