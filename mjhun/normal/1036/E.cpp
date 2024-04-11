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

ll gcd(ll a, ll b){
	while(b){
		ll c=a%b;
		a=b;b=c;
	}
	return a;
}

struct pt {
	ll x,y;
	pt(ll x, ll y):x(x),y(y){}
	pt(){}
	ll norm2(){return *this**this;}
	bool operator==(pt p){return x==p.x&&y==p.y;}
	pt operator+(pt p){return pt(x+p.x,y+p.y);}
	pt operator-(pt p){return pt(x-p.x,y-p.y);}
	pt operator*(ll t){return pt(x*t,y*t);}
	ll operator*(pt p){return x*p.x+y*p.y;}
	ll operator%(pt p){return x*p.y-y*p.x;}
	bool operator<(pt p)const{return x<p.x||x==p.x&&y<p.y;}
	void in(){scanf("%lld%lld",&x,&y);}
};

#define DINF (1<<30)

struct ln {
	pt p,pq;
	ln(pt p, pt q):p(p),pq(q-p){}
	ln(){}
	bool seghas(pt r){return (r-p)*(r-(p+pq))<=0;}
	bool operator/(ln l){return pq%l.pq==0;}
	pt operator^(ln l){
		if(*this/l)return pt(DINF,DINF);
		ll a=(p-l.p)%pq;
		ll b=l.pq%pq;ll bb=b;
		ll sx=l.pq.x,sy=l.pq.y;

		ll g=gcd(sx,b);
		sx/=g;b/=g;
		if(a%b)return pt(DINF,DINF);
		sx*=a/b;

		b=bb;
		g=gcd(sy,b);
		sy/=g;b/=g;
		if(a%b)return pt(DINF,DINF);
		sy*=a/b;

		pt r=l.p+pt(sx,sy);
		if(max(abs(r.x),abs(r.y))>1000000)r.x=DINF;
		return r;
	}
};

int n;
ll r;
pt p[1024],q[1024];
map<pt,int> w;
int asd[1024];

ll doit(pt p){
	ll x=abs(p.x),y=abs(p.y);
	return 1+gcd(x,y);
}

int main(){
	fore(i,0,1024)asd[i]=i*(i-1)/2;
	scanf("%d",&n);
	fore(i,0,n){
		p[i].in();q[i].in();
		r+=doit(p[i]-q[i]);
	}
	fore(i,0,n)fore(j,i+1,n){
		ln l0(p[i],q[i]);
		ln l1(p[j],q[j]);
		pt z=l0^l1;
		if(z.x<DINF&&l0.seghas(z)&&l1.seghas(z)){
			w[z]++;
		}
	}
	for(auto p:w){
		int x=p.snd;
		int i=lower_bound(asd,asd+1024,x)-asd;
		assert(asd[i]==x);
		r-=i-1;
	}
	printf("%lld\n",r);
	return 0;
}