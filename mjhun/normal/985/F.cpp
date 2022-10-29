#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(n) ((int)(n).size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

ll mul(ll a, ll b, ll m) {
	ll r=a*b-(ll)((long double)a*b/m+.5)*m;
	return r<0?r+m:r;
}
struct Hash {
	ll MOD=212345678987654321LL,P=1777771,PI=106955741089659571LL;
	vector<ll> h,pi;
	Hash(string& s){
		assert(mul(P,PI,MOD)==1);
		h.resize(s.size()+1);pi.resize(s.size()+1);h[0]=0;pi[0]=1;
		ll p=1;
		fore(i,1,s.size()+1){
			h[i]=(h[i-1]+mul(p,s[i-1],MOD))%MOD;pi[i]=mul(pi[i-1],PI,MOD);
			p=mul(p,P,MOD);
		}
	}
	ll get(int s, int e){return mul(((h[e]-h[s]+MOD)%MOD),pi[s],MOD);}
};

vector<Hash> h;
string a[26];

int main(){FIN;
  int n,q,x,y,l;
  string s;
  cin >> n >> q >> s;
  fore(i,0,26){
    fore(j,0,n){
      if(s[j] == 'a'+i) a[i]+='1';
      else a[i] += '0';
    }
    h.pb(Hash(a[i]));
  }
  while(q--){
    cin >> x >> y >> l;
    multiset<ll> h2;
    fore(i,0,26){
      h2.insert(h[i].get(y-1, y-1+l));
    }
    int flag = 1;
    fore(i,0,26){
      ll now = h[i].get(x-1,x-1+l);
      if(h2.find(now) == h2.end()){
        cout << "NO\n";
        flag = 0;
        break;
      }
      h2.erase(h2.find(now));
    }
    if(flag){
      cout << "YES\n";
    }
  }
}