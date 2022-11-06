#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ggdem=b;i<ggdem;++i)
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define mset(a,v) memset((a),(v),sizeof(a))
#define FIN ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;

typedef ll tf;
typedef vector<tf> poly;

// FFT
struct CD {
	double r,i;
	CD(double r=0, double i=0):r(r),i(i){}
	double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const double pi=acos(-1.0);

const int MAXN=1<<20;

CD cp1[MAXN+9],cp2[MAXN+9];
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		double z=2*pi/m*(inv?-1:1); // FFT
		CD wi=CD(cos(z),sin(z)); // FFT
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n; // FFT
}
poly multiply(poly& p1, poly& p2){
	int n=p1.size()+p2.size()+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0,cp2[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	fore(i,0,p2.size())cp2[i]=p2[i];
	dft(cp1,m,false);dft(cp2,m,false);
	fore(i,0,m)cp1[i]=cp1[i]*cp2[i];
	dft(cp1,m,true);
	poly res;
	n-=2;
	fore(i,0,n)res.pb((tf)floor(cp1[i].real()+0.5)); // FFT
	return res;
}

bool isprime[MAXN];
vector<ll> prime;
ll SPF[MAXN];

void sieve(int n){
    isprime[0] = isprime[1] = false;
    fore(i,2,n+1){
        if(isprime[i]) prime.push_back(i), SPF[i] = i;
        for(int j=0; j<SZ(prime)&&i*prime[j]<=n&&prime[j]<=SPF[i]; j++){
            isprime[i*prime[j]] = false;
            SPF[i*prime[j]] = prime[j];
        }
    }
}

vector<ll> div(ll n){
	map<ll,ll> mp;
	ll va=n;
	while(va>1){
		mp[SPF[va]]++;
		va/=SPF[va];
	}
	vector<ll> res={1};
	for(auto i:mp){
		fore(ii,0,SZ(res)){
			ll prod=1;
			fore(j,0,i.snd){
				prod*=i.fst;
				res.pb(res[ii]*prod);
			}
		}
	}
	sort(ALL(res));
	reverse(ALL(res));
	return res;
}

vector<ll> p[2],res;

int main(){FIN;
	ll n,x,y; cin>>n>>x>>y;
	ll a[n+1];
	fore(i,0,n+1)cin>>a[i];
	
	fore(k,0,2)p[k]=vector<ll> (200005,0);
	fore(i,0,n+1){
		p[0][a[i]]++;
		p[1][200000-a[i]]++;
	}
	fore(k,0,2)while(p[k].back()==0)p[k].pop_back();
	res=multiply(p[0],p[1]);
	reverse(ALL(res));
	fore(i,0,200001)res.pop_back();
	fore(i,0,y+1)res.pb(0);
	reverse(ALL(res));
	mset(isprime,true);
	sieve(500000);
	ll q; cin>>q;
	while(q--){
		ll l; cin>>l;
		auto d=div(l/2);
		ll br=0;
		for(auto i:d){
			if(i<SZ(res)&&res[i]){
				cout<<2*i<<" ";
				br++; break;
			}
		}
		if(br)continue;
		cout<<"-1 ";
	}
	
	return 0;
}