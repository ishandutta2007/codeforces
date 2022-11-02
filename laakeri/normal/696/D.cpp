#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll modmul(ll a, ll b, ll mod){
	if (b<0) return mod-((modmul(a, -b, mod)+mod)%mod);
	if (b==0) return 0;
	if (b%2==0){
		a=modmul(a, b/2ll, mod);
		return (a+a)%mod;
	}
	return (a+modmul(a, b-1ll, mod))%mod;
}

ll ee(ll ca, ll cb, ll xa, ll xb, ll&x) {
	if (cb) return ee(cb, ca%cb, xb, xa-(ca/cb)*xb, x);
	x = xa;
	return ca;
}

pair<int, pair<ll, ll>> crt(vector<ll> as, vector<ll> ms) {
	ll aa = 0, mm = 1, d, a, x;
	for (int i = 0; i < (int) as.size(); i++) {
		d = ee(ms[i], mm, 1, 0, x);
		if ((aa-as[i])%d) return {-1,{0,0}};
		a = ms[i]/d;
		mm *= a;
		aa = (as[i] + modmul((aa-as[i]), modmul(a, x, mm), mm))%mm;
	}
	if (aa < 0) aa += mm;
	return {1, {aa, mm}};
}

ll powmod(ll a, ll p, ll modd) {
	if (p==0) return 1;
	if (p%2==0) {
		a=powmod(a, p/2, modd);
		return (a*a)%modd;
	}
	return (a*powmod(a, p-1, modd))%modd;
}

ll invp(ll a, ll p) {
	return powmod(a, p - 2, p);
}

vector<ll> solve(vector<ll> S, ll mod) {
	vector<ll> C = {1};
	vector<ll> B = {1};
	ll L = 0;
	ll m = 1;
	ll b = 1;
	ll N = S.size();
	for (ll i = 0; i < N; i++) {
		ll d = S[i];
		for (ll j = 1; j <= L; j++) {
			d += C[j]*S[i - j];
			d %= mod;
		}
		if (d == 0) {
			m++;
		} else if (2*L <= i) {
			vector<ll> T = C;
			ll a = (invp(b, mod)*d)%mod;
			for (int j=0;j<i+1-2*L;j++){
				C.push_back(0);
			}
			L=i+1-L;
			for (ll j = m; j <= L; j++) {
				C[j] -= a*B[j - m];
				C[j] %= mod;
			}
			B = T;
			b = d;
			m = 1;
		} else {
			ll a = (invp(b, mod)*d)%mod;
			for (ll j = m; j < m+(int)B.size(); j++) {
				C[j] -= a*B[j - m];
				C[j] %= mod;
			}
			m++;
		}
	}
	for (ll i = 0; i <= L; i++) {
		C[i] += mod;
		C[i] %= mod;
	}
	return C;
}

struct LinearRecurrence {
	vector<vector<ll> > mat;
	vector<ll> seq;
	ll mod;
	vector<vector<ll> > mul(vector<vector<ll> > a, vector<vector<ll> > b) {
		int n=a.size();
		vector<vector<ll> > ret(n);
		for (int i=0;i<n;i++){
			ret[i].resize(n);
			for (int j=0;j<n;j++){
				ret[i][j]=0;
				for (int k=0;k<n;k++){
					ret[i][j]+=a[i][k]*b[k][j];
				}
				ret[i][j]%=mod;
			}
		}
		return ret;
	}
	vector<vector<ll> > pot(vector<vector<ll> > m, ll p) {
		if (p==1) return m;
		if (p%2==0) {
			m=pot(m, p/2);
			return mul(m, m);
		}
		else{
			return mul(m, pot(m, p-1));
		}
	}
	ll get(ll i){
		if (i<(ll)mat.size()){
			return seq[i];
		}
		vector<vector<ll> > a=pot(mat, i-(ll)mat.size()+1);
		ll v=0;
		for (int i=0;i<(int)mat.size();i++){
			v+=a[0][i]*seq[(int)mat.size()-i-1];
			v%=mod;
		}
		return v;
	}
	LinearRecurrence(vector<ll> S, ll mod_) {
		seq=S;
		mod=mod_;
		vector<ll> C=solve(S, mod);
		int n=C.size()-1;
		mat.resize(n);
		for (int i=0;i<n;i++) {
			mat[i].resize(n);
		}
		for (int i=0;i<n;i++){
			mat[0][i]=(mod-C[i+1])%mod;
		}
		for (int i=1;i<n;i++){
			mat[i][i-1]=1;
		}
	}
};

ll w[222];

int issb(string a, string b){
	if (b.size() > a.size()) return 0;
	int r=0;
	for (int i=0;i<(int)a.size();i++){
		int f=0;
		for (int j=0;j<(int)b.size();j++){
			if (i+j>=(int)a.size()||a[i+j]!=b[j]){
				f=1;
				break;
			}
		}
		if (f==0) r++;
	}
	return r;
}

ll va[222][222];
ll le[222][222];

string ss[222];
ll ww[222];
ll iw[222];

int n;

string cut(string a, string b){
	for (int i=0;i<(int)a.size();i++){
		if (i+(int)b.size()>(int)a.size()){
			string r;
			int f=0;
			for (int j=0;i+j<(int)a.size();j++){
				if (b[j]!=a[i+j]) {
					f=1;
					break;
				}
				r+=b[j];
			}
			if (!f) return r;
		}
	}
	return "";
}

ll getiw(string s){
	ll r=0;
	for (int i=0;i<n;i++){
		r+=ww[i]*issb(s, ss[i]);
	}
	return r;
}

ll dp[1311][222];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll l;
	cin>>n>>l;
	map<string, ll> sw;
	for (int i=0;i<n;i++){
		cin>>w[i];
	}
	int tol=0;
	for (int i=0;i<n;i++){
		string s;
		cin>>s;
		sw[s]+=w[i];
		tol+=(int)s.size();
	}
	n=0;
	for (auto t:sw){
		ss[n]=t.F;
		ww[n]=t.S;
		n++;
	}
	for (int i=0;i<n;i++){
		iw[i]=getiw(ss[i]);
	}
	for (int i=0;i<n;i++){
		for (int ii=0;ii<n;ii++){
			string c=cut(ss[i], ss[ii]);
			le[i][ii]=(int)ss[ii].size()-(int)c.size();
			va[i][ii]=iw[ii]-getiw(c);
		}
	}
	for (int i=0;i<n;i++){
		dp[ss[i].size()][i]=iw[i];
	}
	for (int i=0;i<=1000;i++){
		for (int j=0;j<n;j++){
			if (dp[i][j]>0){
				for (int jj=0;jj<n;jj++){
					if (dp[i][j]+va[j][jj]>dp[i+le[j][jj]][jj]){
						dp[i+le[j][jj]][jj]=dp[i][j]+va[j][jj];
					}
				}
			}
		}
	}
	vector<ll> lol1;
	vector<ll> lol2;
	ll mod1=1e9+7;
	ll mod2=1e9+9;
	ll be=0;
	for (int i=0;i<=1000;i++){
		for (int j=0;j<n;j++){
			be=max(be, dp[i][j]);
		}
		lol1.push_back(be%mod1);
		lol2.push_back(be%mod2);
	}
	LinearRecurrence lr1(lol1, mod1);
	LinearRecurrence lr2(lol2, mod2);
	ll v1=lr1.get(l);
	ll v2=lr2.get(l);
	auto v=crt({v1, v2}, {mod1, mod2});
	cout<<v.S.F<<endl;
}