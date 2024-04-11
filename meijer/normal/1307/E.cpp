#include <bits/stdc++.h>
using namespace std;

//macros
typedef long long ll;
typedef pair<ll, ll> ii;
typedef tuple<int, int, int> iii;
typedef vector<ll> vi;
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef vector<ll> vll;
#define REP(a,b,c) for(int a=int(b); a<int(c); a++)
#define RE(a,c) REP(a,0,c)
#define RE1(a,c) REP(a,1,c+1)
#define REI(a,b,c) REP(a,b,c+1)
#define REV(a,b,c) for(int a=int(c-1); a>=int(b); a--)
#define INF 1e9
#define pb push_back
#define fi first
#define se second

//===================//
//  Added libraries  //
//===================//

// mod library
ll MOD=1e9+7;

inline ll mod(ll x_) {
	return (x_)%MOD;
}
ll modpow(ll x_, ll N_) {
    if(N_ == 0) return 1;
    ll a = modpow(x_,N_/2);
    a = (a*a)%MOD;
    if(N_%2) a = (a*x_)%MOD;
    return a;
}
ll inv(ll x_) {
    return modpow(x_, MOD-2);
}
class mi {
public:
    mi(ll v=0) {value = v;}
    mi  operator+ (ll rs) {return mod(value+rs);}
    mi  operator- (ll rs) {return mod(value-rs+MOD);}
    mi  operator* (ll rs) {return mod(value*rs);}
    mi  operator/ (ll rs) {return mod(value*inv(rs));}
    mi& operator+=(ll rs) {*this = (*this)+rs; return *this;}
    mi& operator-=(ll rs) {*this = (*this)-rs; return *this;}
    mi& operator*=(ll rs) {*this = (*this)*rs; return *this;}
    mi& operator/=(ll rs) {*this = (*this)/rs; return *this;}
    operator ll&() {return value;}

    ll value;
};
typedef vector<mi> vmi;

//===================//
//end added libraries//
//===================//

void program();
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	program();
}



//===================//
//   begin program   //
//===================//

const int MX = 1e4;
int n, m, s[MX], f[MX], h[MX];
int cntS[MX], mx=0, cur=0;
bitset<MX> l, r;
int inUseL[MX], inUseR[MX];
mi ways=0;

void addInUse(int i) {
	if(inUseL[i] == 0 && inUseR[i] == 0) return;
	else if(inUseL[i] <= 1 && inUseR[i] <= 1) cur += 1;
	else if(inUseL[i] >= 1 && inUseR[i] >= 1) cur += 2;
	else cur += 1;
}
void removeInUse(int i) {
	if(inUseL[i] == 0 && inUseR[i] == 0) return;
	else if(inUseL[i] <= 1 && inUseR[i] <= 1) cur -= 1;
	else if(inUseL[i] >= 1 && inUseR[i] >= 1) cur -= 2;
	else cur -= 1;
}

void program() {
	cin>>n>>m;
	RE(i,n) cin>>s[i], s[i]--;
	RE(i,m) cin>>f[i]>>h[i], f[i]--;
	l.reset(); r.reset();

	RE(i,n) cntS[i] = 0;
	RE(i,n) {
		cntS[s[i]]++;
		RE(j,m) if(f[j] == s[i] && h[j] == cntS[s[i]]) l[i]=1;
	}

	RE(i,n) cntS[i] = 0;
	REV(i,0,n) {
		cntS[s[i]]++;
		RE(j,m) if(f[j] == s[i] && h[j] == cntS[s[i]]) r[i]=1;
	}

	RE(i,n) inUseL[i]=inUseR[i]=0;
	RE(i,n) if(r[i]) {
		removeInUse(s[i]);
		inUseR[s[i]]++;
		addInUse(s[i]);
	}

	mx=cur;
	RE(i,n) {
		if(r[i]) {
			removeInUse(s[i]);
			inUseR[s[i]]--;
			addInUse(s[i]);
		}
		if(l[i]) {
			removeInUse(s[i]);
			inUseL[s[i]]++;
			addInUse(s[i]);
		}
		mx = max(mx, cur);
	}

	RE(i,n) inUseL[i]=inUseR[i]=0;
	cur = 0;
	
	RE(i,n) if(r[i]) {
		removeInUse(s[i]);
		inUseR[s[i]]++;
		addInUse(s[i]);
	}
	RE(i,n) {
		if(i == 0 && cur == mx) {
			mi added=1;
			RE(j,n) if(inUseR[j]) added *= inUseR[j];
			ways += added;
		}
		if(r[i]) {
			removeInUse(s[i]);
			inUseR[s[i]]--;
			addInUse(s[i]);
		}
		if(l[i]) {
			removeInUse(s[i]);
			inUseL[s[i]]++;
			addInUse(s[i]);
			if(cur == mx) {
				mi added=1;
				RE(j,n) {
					if(j == s[i]) {
						if(inUseR[j]) {
							if(inUseR[j] >= inUseL[j]) 	added *= max(1,inUseR[j]-1);
							else 						added *= inUseR[j];
						}
					} else {
						if(inUseL[j] && inUseR[j]) {
							mi small=inUseL[j], big=inUseR[j];
							if(small > big) swap(small, big);
							if(small == 1 && big == 1) big=3;
							big = max(1LL, ll(big-1));
							added *= small*big;
						} else {
							if(inUseL[j]) added *= inUseL[j];
							if(inUseR[j]) added *= inUseR[j];
						}
					}
				}
				ways += added;
			}
		}
	}

	cout<<mx<<" "<<ways<<endl;

}