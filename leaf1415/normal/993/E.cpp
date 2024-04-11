#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

#define PI 3.141592653589793238

int rev(int x, int n)
{
	int ret = 0;
	for(int i = 0; i < n; i++){
		ret <<= 1;
		ret |= (x>>i) & 1;
	}
	return ret;
}

//f[]F[]
void DFT(complex<double> f[], complex<double> F[], int n)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) F[rev(i, n)] = f[i];
	
	complex<double> a, b, x, z;
	for(int i = 1; i <= n; i++){
		int l = 1<<i;
		z = complex<double>(cos(2*PI/l), sin(2*PI/l));
		for(int j = 0; j < N/l; j++){
			x = complex<double>(1, 0);
			for(int k = 0; k < l/2; k++){
				a = F[j*l+k], b = F[j*l+k+l/2];
				F[j*l+k] = a + x * b;
				F[j*l+k+l/2] = a - x * b;
				x *= z;
			}
		}
	}
}

//f[]F[]
void IDFT(complex<double> F[], complex<double> f[], int n)
{
	int N = 1<<n;
	for(int i = 0; i < N; i++) f[rev(i, n)] = F[i];
	
	complex<double> a, b, x, z;
	for(int i = 1; i <= n; i++){
		int l = 1<<i;
		z = complex<double>(cos(2*PI/l), -sin(2*PI/l));
		for(int j = 0; j < N/l; j++){
			x = complex<double>(1, 0);
			for(int k = 0; k < l/2; k++){
				a = f[j*l+k], b = f[j*l+k+l/2];
				f[j*l+k] = a + x * b;
				f[j*l+k+l/2] = a - x * b;
				x *= z;
			}
		}
	}
	for(int i = 0; i < N; i++) f[i] /= N;
}

llint round(complex<double> c){
	return (llint)(c.real()+0.5);
}

ll n, x;
ll a[200005];
vector<ll> vec;
complex<double> f[1<<19], g[1<<19], F[1<<19], G[1<<19];
ll ans[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> x;
	rep(i, 1, n){
		cin >> a[i];
		if(a[i] >= x) a[i] = 0;
		else a[i] = 1;
	}
	
	int cnt = 0;
	rep(i, 1, n){
		if(a[i] == 0) cnt++;
		else{
			vec.push_back(cnt+1);
			cnt = 0;
		}
	}
	vec.push_back(cnt+1);
	
	rep(i, 0, (int)vec.size()-1) f[i] = g[i] = vec[i];
	reverse(g, g+(int)vec.size());
	
	//rep(i, 0, (int)vec.size()) cout << f[i] << " "; cout << endl;
	//rep(i, 0, (int)vec.size()) cout << g[i] << " "; cout << endl;
	
	DFT(f, F, 19);
	DFT(g, G, 19);
	
	rep(i, 0, (1<<19)-1) F[i] *= G[i];
	
	IDFT(F, f, 19);
	
	//rep(i, 0, 2*n) cout << round(f[i]) << " "; cout << endl;
	
	rep(i, 1, n) ans[i] = round(f[(int)vec.size()-1+i]);
	for(auto x : vec) ans[0] += x * (x-1)/2;
	rep(i, 0, n) cout << ans[i] << " "; cout << endl;
	
	return 0;
}