#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

const ll MOD=1000000007;

ll be(ll b, ll e, ll mod){
  ll r=1;
  while(e)if(e&1)r=(r*b)%mod,e^=1; else b=(b*b)%mod,e/=2;
  return r;
}

ll discrete_log(ll a,ll b,ll m) {
    a%=m, b%=m;
    if(b == 1) return 0;
    int cnt=0;
    ll tmp=1;
    for(int g=__gcd(a,m);g!=1;g=__gcd(a,m)) {
        if(b%g) return -1;
        m/=g, b/=g;
        tmp = tmp*a/g%m;
        ++cnt;
        if(b == tmp) return cnt;
    }
    map<ll,int> w;
    int s = ceil(sqrt(m));
    ll base = b;
    fore(i,0,s) {
        w[base] = i;
        base=base*a%m;
    }
    base=be(a,s,m);
    ll key=tmp;
    fore(i,1,s+2) {
        key=base*key%m;
        if(w.count(key)) return i*s-w[key]+cnt;
    }
    return -1;
}

typedef vector<vector<ll> > Matrix;
Matrix ones(int n) {
	Matrix r(n,vector<ll>(n));
	fore(i,0,n)r[i][i]=1;
	return r;
}
Matrix operator*(Matrix &a, Matrix &b) {
	int n=SZ(a),m=SZ(b[0]),z=SZ(a[0]);
	Matrix r(n,vector<ll>(m));
	fore(i,0,n)fore(j,0,m)fore(k,0,z)
		r[i][j]+=a[i][k]*b[k][j],r[i][j]%=(MOD-1);
	return r;
}
Matrix be(Matrix b, ll e){
	Matrix r=ones(SZ(b));
	while(e){if(e&1LL)r=r*b;b=b*b;e/=2;}
	return r;
}

int main(){FIN;
	ll n,f[3],c; cin>>n>>f[0]>>f[1]>>f[2]>>c;
	ll ce=discrete_log(5,c,MOD);
	ll fe[3];
	fe[0]=discrete_log(5,f[0],MOD);
	fe[1]=discrete_log(5,f[1],MOD);
	fe[2]=discrete_log(5,f[2],MOD);
	Matrix M=ones(5);
	M[0][0]--; M[1][1]--;
	M[0][1]++;
	M[1][2]++;
	M[2][3]++;
	M[3][4]++;
	M[2][0]++;
	M[2][1]++;
	Matrix V;
	fore(i,0,5){
		vector<ll> v;
		if(i<3){
			v.pb(fe[i]);
			V.pb(v);
		}else{
			v.pb(2*ce);
			V.pb(v);
		}
	}
	Matrix A=be(M,n-3);
	A=A*V;
	cout<<be(5,A[2][0],MOD);
	
	return 0;
}