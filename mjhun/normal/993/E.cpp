#include <bits/stdc++.h>
#ifdef DEMETRIO
#define deb(...) fprintf(stderr,__VA_ARGS__)
#define deb1(x) cerr << #x << " = " << x << endl
#else
#define deb(...) 0
#define deb1(x) 0
#endif
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define SZ(x) ((int)(x).size())
#define mset(a,v) memset(a,v,sizeof(a))
#define mcpy(a,b) memcpy(a,b,sizeof(a))
using namespace std;
typedef long long ll;

#define MAXN (1<<19)

struct CD {
	long double r,i;
	CD(long double r=0, long double i=0):r(r),i(i){}
	long double real()const{return r;}
	void operator/=(const int c){r/=c, i/=c;}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r-a.i*b.i,a.r*b.i+a.i*b.r);}
CD operator+(const CD& a, const CD& b){return CD(a.r+b.r,a.i+b.i);}
CD operator-(const CD& a, const CD& b){return CD(a.r-b.r,a.i-b.i);}
const long double pi=acosl(-1.0);
CD cp1[MAXN+9],cp2[MAXN+9];  // MAXN must be power of 2 !!
int R[MAXN+9];
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		long double z=2*pi/m*(inv?-1:1);
		CD wi=CD(cos(z),sin(z));
		for(int j=0;j<n;j+=m){
			CD w=1;
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv)fore(i,0,n)a[i]/=n;
}
vector<ll> multiply(vector<ll>& p1, vector<ll>& p2){
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
	vector<ll> res;
	n-=2;
	fore(i,0,n)res.pb((ll)floor(cp1[i].real()+0.5));
	return res;
}

vector<ll> p0,p1,r;
ll x;int n;

int main(){
	scanf("%d%lld",&n,&x);
	p0.resize(n+1);p1.resize(n+1);
	ll s=0;
	p0[0]=1;
	fore(i,0,n){
		ll a;
		scanf("%lld",&a);
		s+=a<x;
		p0[s]++;
	}
	p1=p0;
	reverse(p1.begin(),p1.end());
	r=multiply(p0,p1);
	//for(ll t:r)printf(" %lld",t);puts("");
	printf("%lld",(r[n]-n-1)/2);
	fore(i,n+1,SZ(r))printf(" %lld",r[i]);
	puts("");
	return 0;
}