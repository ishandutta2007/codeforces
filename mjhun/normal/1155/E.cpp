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

#define MOD 1000003

int pm(int a, int e){
	int r=1;
	while(e){
		if(e&1)r=1LL*r*a%MOD;
		e>>=1;
		a=1LL*a*a%MOD;
	}
	return r;
}

struct tp {
	int x;
	tp(int x):x(x) {}
	tp():x(0){}
	tp operator+(tp t){return tp((x+t.x)%MOD);}
	tp operator-(tp t){return tp((x-t.x+MOD)%MOD);}
	tp operator*(tp t){return tp((1LL*x*t.x)%MOD);}
	tp operator-(){return tp(0)-*this;}
};

tp inv(tp t){return tp(pm(t.x,MOD-2));}

template<class T=tp>
struct poly {  // poly<> : 1 variable, poly<poly<>>: 2 variables, etc.
	vector<T> c;
	T& operator[](int k){return c[k];}
	poly(vector<T>& c):c(c){}
	poly(initializer_list<T> c):c(c){}
	poly(int k):c(k){}
	poly(){}
	poly operator+(poly<T> o){
		int m=c.size(),n=o.c.size();
		poly res(max(m,n));
		fore(i,0,m)res[i]=res[i]+c[i];
		fore(i,0,n)res[i]=res[i]+o.c[i];
		return res;
	}
	poly operator*(tp k){
		poly res(c.size());
		fore(i,0,c.size())res[i]=c[i]*k;
		return res;
	}
	poly operator*(poly o){
		int m=c.size(),n=o.c.size();
		poly res(m+n-1);
		fore(i,0,m)fore(j,0,n)res[i+j]=res[i+j]+c[i]*o.c[j];
		return res;
	}
	poly operator-(poly<T> o){return *this+(o*-1);}
	T operator()(tp v){
		T sum(0);
		for(int i=c.size()-1;i>=0;--i)sum=sum*v+c[i];
		return sum;
	}
};
pair<poly<>,tp> ruffini(poly<> p, tp r){ // returns pair (result,rem)
	int n=p.c.size()-1;
	vector<tp> b(n);
	b[n-1]=p[n];
	for(int k=n-2;k>=0;--k)b[k]=p[k+1]+r*b[k+1];
	return mp(poly<>(b),p[0]+r*b[0]);
}
// only for double polynomials
poly<> interpolate(vector<tp> x, vector<tp> y){ //TODO TEST
	poly<> q={tp(1)},S={tp(0)};
	for(tp a:x)q=poly<>({-a,tp(1)})*q;
	fore(i,0,x.size()){
		poly<> Li=ruffini(q,x[i]).fst;
		Li=Li*inv(Li(x[i])); // change for int polynomials
		S=S+Li*y[i];
	}
	return S;
}

int main(){
	vector<tp> x,y;
	fore(i,0,11){
		printf("? %d\n",i);fflush(stdout);
		int t;
		scanf("%d",&t);
		x.pb(tp(i));y.pb(tp(t));
	}
	auto p=interpolate(x,y);
	int r=-1;
	fore(i,0,MOD)if(!p(tp(i)).x){r=i;break;}
	printf("! %d\n",r);
	return 0;
}