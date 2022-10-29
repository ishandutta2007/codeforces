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


#define MOD 998244353
#define RT 3

ll pm(ll a, ll e){
	ll r=1;
	while(e){
		if(e&1)r=r*a%MOD;
		e>>=1;
		a=a*a%MOD;
	}
	return r;
}

struct CD {
	ll r;
	CD(ll r=0):r(r){}
};
CD operator*(const CD& a, const CD& b){
	return CD(a.r*b.r%MOD);
}
CD operator+(const CD& a, const CD& b){
	ll r=a.r+b.r;
	if(r>=MOD)r-=MOD;
	return CD(r);
}
CD operator-(const CD& a, const CD& b){
	ll r=a.r-b.r+MOD;
	if(r>=MOD)r-=MOD;
	return CD(r);
}
#define MAXN (1<<20)
CD cp1[MAXN+9];
int R[MAXN+9];
CD root(int n, bool inv){
	ll r=pm(RT,(MOD-1)/n);
	return CD(inv?pm(r,MOD-2):r);
}
void dft(CD* a, int n, bool inv){
	fore(i,0,n)if(R[i]<i)swap(a[R[i]],a[i]);
	for(int m=2;m<=n;m*=2){
		CD wi=root(m,inv);
		for(int j=0;j<n;j+=m){
			CD w(1);
			for(int k=j,k2=j+m/2;k2<j+m;k++,k2++){
				CD u=a[k];CD v=a[k2]*w;a[k]=u+v;a[k2]=u-v;w=w*wi;
			}
		}
	}
	if(inv){
		CD z(pm(n,MOD-2));
		fore(i,0,n)a[i]=a[i]*z;
	}
}
vector<int> polexp(vector<int>& p1, int e){
	int n=(SZ(p1)-1)*e+1;
	int m=1,cnt=0;
	while(m<=n)m+=m,cnt++;
	fore(i,0,m){R[i]=0;fore(j,0,cnt)R[i]=(R[i]<<1)|((i>>j)&1);}
	fore(i,0,m)cp1[i]=0;
	fore(i,0,p1.size())cp1[i]=p1[i];
	dft(cp1,m,false);
	fore(i,0,m)cp1[i]=CD(pm(cp1[i].r,e));
	dft(cp1,m,true);
	vector<int> res;
	fore(i,0,n)res.pb(cp1[i].r);
	return res;
}

int n,k;

int main(){
	scanf("%d%d",&n,&k);
	vector<int> p(10);
	fore(i,0,k){
		int d;
		scanf("%d",&d);
		p[d]=1;
	}
	auto v=polexp(p,n/2);
	ll r=0;
	fore(i,0,SZ(v))r=(r+1LL*v[i]*v[i])%MOD;
	printf("%lld\n",r);
	return 0;
}