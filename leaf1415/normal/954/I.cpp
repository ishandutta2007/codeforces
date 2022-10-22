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
#define mod 1000000007

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

string s, t;
int S[6][130005], T[6][130005];
bool b[130005][6][6];
complex<double> f[1<<18], g[1<<18], F[1<<18], G[1<<18];
bool used[6];

void dfs(int k, int v)
{
	used[v] = true;
	rep(i, 0, 5){
		if(used[i] || !(b[k][v][i] || b[k][i][v])) continue;
		dfs(k, i);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	rep(i, 0, (int)s.size()-1) S[s[i]-'a'][i] = 1;
	rep(i, 0, (int)t.size()-1) T[t[i]-'a'][i] = 1;
	
	rep(i, 0, 5) reverse(T[i], T[i]+(int)t.size());
	
	rep(i, 0, 5){
		rep(j, 0, 5){
			rep(k, 0, (1<<18)-1){
				f[k] = g[k] = 0;
				if(k < s.size()) f[k] = S[i][k];
				if(k < t.size()) g[k] = T[j][k];
			}
			
			DFT(f, F, 18), DFT(g, G, 18);
			rep(k, 0, (1<<18)-1) F[k] *= G[k];
			IDFT(F, f, 18);
			rep(k, 0, (int)s.size()-1){
				if(round(f[(int)t.size()-1+k])) b[k][i][j] = true;
			}
		}
	}
	
	for(int i = 0; i+(int)t.size()-1 < (int)s.size(); i++){
		rep(j, 0, 5) used[j] = false;
		ll ans = 0;
		rep(j, 0, 5){
			if(!used[j]) dfs(i, j), ans++;
		}
		ans = 6 - ans;
		cout << ans << " ";
	}
	cout << endl;
	
	return 0;
}