#include <bits/stdc++.h>
using namespace std;

#define fru(j,n) for(int j=0; j<(n); ++j)
#define tr(it,v) for(auto it=(v).begin(); it!=(v).end(); ++it)
//#define tr(it,v) for(typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define x first
#define y second
#define pb push_back
#define ALL(G) (G).begin(),(G).end()

#if 1
	#define DEB printf
#else
	#define DEB(...)
#endif

typedef long long ll;
typedef long long LL;
typedef double D;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int inft = 1000000009;
const int mod = 1000000007;
const D PI = acos(-1);

struct mat4 { D m[4][4]; };
struct vec4 { D v[4]; };

mat4 operator*(const mat4 &a, const mat4 &b) {
	mat4 ret = {0};
	fru(i,4) fru(j,4) fru(k,4) ret.m[i][j] += a.m[i][k] * b.m[k][j];
	return ret;
}

vec4 operator*(const mat4 &a, const vec4 &b) {
	vec4 ret = {0};
	fru(i,4) fru(j,4) ret.v[i] += a.m[i][j] * b.v[j];
	return ret;
}

void init(mat4 &m) { fru(j,4) m.m[j][j] = 1; }
void init(vec4 &v) { v.v[2] = 1; }
void init_trans(mat4 &m, D d) { init(m); m.m[0][2] = m.m[1][3] = d; }
void init_rot(mat4 &m, D a) {
	init(m);
	m.m[2][2] = cos(a);
	m.m[2][3] = sin(a);
	m.m[3][2] = -sin(a);
	m.m[3][3] = cos(a);
}

const int MAXN = 1024*512;
mat4 drz[2*MAXN];

void napraw(int u) {
	drz[u] = drz[2*u+1] * drz[2*u];
}

vec4 compute(int u) {
	int a = MAXN, b = MAXN+u-1;
	mat4 ma = {0}, mb = {0};
	init(ma); init(mb);
	while(a<=b) {
		if(a%2==1) ma = drz[a] * ma;
		if(b%2==0) mb = mb * drz[b];
		a = (a+1)/2;
		b = (b-1)/2;
	}
	vec4 v = {0}; init(v);
	return mb*(ma*v);
}

void wypisz(const vec4 &v) { fru(i,2) printf("%.9lf ",v.v[i]); puts(""); }

void solve() {
	int n,m;
	scanf("%d%d",&n,&m);
	fru(i,MAXN) init_trans(drz[i+MAXN], 1);
	for(int i=MAXN-1; i>0; i--) napraw(i);
	fru(q,m) {
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		y--; y+=MAXN;
		if(x==1) {
			mat4 nop = {0};
			init_trans(nop, z);
			//drz[y] = drz[y] * nop;
			drz[y] = nop * drz[y];
		} else {
			mat4 nop = {0};
			init_rot(nop, PI*z/180);
			drz[y] = drz[y] * nop;
			//drz[y] = nop * drz[y];
		}
		while(y/=2) napraw(y);
		wypisz(compute(n));
	}
}

int main() {
	int te = 1;
//	scanf("%d",&te);
	fru(ti,te) solve();
	return 0;
}