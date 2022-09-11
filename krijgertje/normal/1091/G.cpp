#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list>  
#include <cassert>
#include <ctime>
#include <climits>
#include <chrono>
#include <random>
using namespace std;

#define PB push_back  
#define MP make_pair  
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  
typedef long long ll;
typedef unsigned long long ull;
ull gcd(ull a, ull b) { return b == 0 ? a : gcd(b, a%b); }

const int BIGINTBITS=32;
const unsigned int BIGINTMASK=(1LL<<BIGINTBITS)-1;

struct BigInt {
	vector<unsigned int> d;
	BigInt() {}
	BigInt(unsigned long long x) { while(x!=0) d.PB(x&BIGINTMASK),x>>=BIGINTBITS; }
	unsigned long long val() const { unsigned long long ret=0; for(int i=SZ(d)-1;i>=0;--i) ret=(ret<<BIGINTBITS)|d[i]; return ret; }
};
void normalize(BigInt &a) { while(SZ(a.d)>0&&a.d[SZ(a.d)-1]==0) a.d.pop_back(); }
int cmp(const BigInt &a,const BigInt &b) { if(SZ(a.d)!=SZ(b.d)) return SZ(a.d)<SZ(b.d)?-1:+1; for(int i=SZ(a.d)-1;i>=0;--i) if(a.d[i]!=b.d[i]) return a.d[i]<b.d[i]?-1:+1; return 0; }
bool operator<(const BigInt &a,const BigInt &b) { return cmp(a,b)<0; }
bool operator<=(const BigInt &a,const BigInt &b) { return cmp(a,b)<=0; }
bool operator==(const BigInt &a,const BigInt &b) { return cmp(a,b)==0; }
BigInt& operator+=(BigInt &a,const BigInt &b) { 
	unsigned long long carry=0;
	for(int i=0;i<SZ(b.d)||carry!=0;++i) {
		if(i<SZ(a.d)) carry+=a.d[i]; else a.d.PB(0);
		if(i<SZ(b.d)) carry+=b.d[i];
		a.d[i]=carry&BIGINTMASK; carry>>=BIGINTBITS;
	}
	return a;
}
BigInt operator+(const BigInt &a,const BigInt &b) { BigInt ret=a; ret+=b; return ret; }
BigInt& operator-=(BigInt &a,const BigInt &b) {
	unsigned long long carry=0;
	for(int i=0;i<SZ(b.d)||carry!=0;++i) {
		if(i<SZ(b.d)) carry+=b.d[i];
		assert(i<SZ(a.d)); if(carry<=a.d[i]) a.d[i]-=carry,carry=0; else a.d[i]+=(1LL<<BIGINTBITS)-carry,carry=1;
	}
	normalize(a); return a;
}
BigInt operator-(const BigInt &a,const BigInt &b) { BigInt ret=a; ret-=b; return ret; }
BigInt operator*(const BigInt &a,const BigInt &b) {
	BigInt ret;
	for(int j=0;j<SZ(b.d);++j) {
		unsigned long long carry=0;
		for(int i=0;i<SZ(a.d)||carry!=0;++i) {
			if(i<SZ(a.d)) carry+=(unsigned long long)a.d[i]*b.d[j];
			if(i+j<SZ(ret.d)) carry+=ret.d[i+j]; else ret.d.PB(0);
			ret.d[i+j]=carry&BIGINTMASK; carry>>=BIGINTBITS;
		}
	}
	return ret;
}
BigInt operator*(const BigInt &a,const unsigned int &b) {
	assert(0<=b&&b<=BIGINTMASK);
	unsigned long long carry=0; BigInt ret;
	if(b==0) return ret;
	for(int i=0;i<SZ(a.d)||carry!=0;++i) {
		if(i<SZ(a.d)) carry+=(unsigned long long)a.d[i]*b;
		if(i<SZ(ret.d)) carry+=ret.d[i]; else ret.d.PB(0);
		ret.d[i]=carry&BIGINTMASK; carry>>=BIGINTBITS;
	}
	return ret;
}
BigInt operator<<(const BigInt &a,const int &shift) {
	assert(shift<BIGINTBITS);
	BigInt ret; unsigned long long carry=0;
	for(int i=0;i<SZ(a.d)||carry!=0;++i) {
		if(i<SZ(a.d)) carry|=((unsigned long long)a.d[i])<<shift;
		ret.d.PB(carry&BIGINTMASK); carry>>=BIGINTBITS;
	}
	return ret;
}
BigInt operator>>(const BigInt &a,const int &shift) {
	assert(shift<BIGINTBITS);
	BigInt ret; unsigned long long carry=0;
	for(int i=0;i<SZ(a.d)||carry!=0;++i) {
		if(i<SZ(a.d)) carry|=((unsigned long long)a.d[i])<<(BIGINTBITS-shift);
		if(i!=0) ret.d.PB(carry&BIGINTMASK); carry>>=BIGINTBITS; 
	}
	return ret;
}
void dividewithremainder(const BigInt &a,const unsigned int &b,BigInt &q,unsigned int &r) {
	assert(1<=b&&b<=BIGINTMASK);
	q.d.resize(SZ(a.d)); unsigned long long carry=0;
	for(int i=SZ(a.d)-1;i>=0;--i) {
		carry<<=BIGINTBITS;
		carry+=a.d[i];
		q.d[i]=carry/b; carry-=(unsigned long long)q.d[i]*b;
	}
	normalize(q); r=carry;
}
BigInt operator/(const BigInt &a,const unsigned int &b) { BigInt q; unsigned int r; dividewithremainder(a,b,q,r); return q; }
unsigned int operator%(const BigInt &a,const unsigned int &b) { BigInt q; unsigned int r; dividewithremainder(a,b,q,r); return r; }
void dividewithremainder(const BigInt &a,const BigInt &b,BigInt &q,BigInt &r) {
	if(a<b) { q.d.clear(); r=a; return; }
	if(SZ(b.d)==1) { unsigned int rr; dividewithremainder(a,b.d[0],q,rr); r=BigInt(rr); return; }
	int shift=0; while(((b.d[SZ(b.d)-1]>>(BIGINTBITS-shift-1))&1)==0) ++shift;
	BigInt u=a<<shift,v=b<<shift; q.d.resize(SZ(u.d)-SZ(v.d)+1);
	//printf("a=%llu b=%llu -> shift=%d -> u=%llu v=%llu\n",a.val(),b.val(),shift,u.val(),v.val());
	r.d.resize(SZ(v.d)); for(int i=0;i<SZ(v.d);++i) r.d[SZ(v.d)-i-1]=u.d[SZ(u.d)-i-1];
	for(int i=SZ(q.d)-1;i>=0;--i) {
		unsigned long long num1=SZ(v.d)<SZ(r.d)?r.d[SZ(v.d)]:0,num2=SZ(v.d)-1<SZ(r.d)?r.d[SZ(v.d)-1]:0;
		unsigned long long num=(num1<<BIGINTBITS)|num2; unsigned int den=v.d[SZ(v.d)-1];
		unsigned int guess=min(num/den,(unsigned long long)BIGINTMASK);
		//printf("i=%d initial guess for %llu/%llu is %u\n",i,r.val(),v.val(),guess);
		while(r<v*guess) --guess;
		//printf("final guess=%u\n",guess);
		//printf("%llu vs %llu*%u=%llu=%llu %s\n",r.val(),v.val(),guess,v.val()*guess,(v*guess).val(),r<v*guess?"yes":"no");
		//REPSZ(j,r.d) printf("r%d = %d\n",j,r.d[j]);
		//REPSZ(j,(v*guess).d) printf("*%d = %d\n",j,(v*guess).d[j]);
		//printf("%d %d\n",SZ(r.d),SZ((v*guess).d));
		q.d[i]=guess;
		r-=v*guess;
		if(i!=0) r.d.insert(r.d.begin(),u.d[i-1]);
	}
	normalize(q); r=r>>shift;
}
BigInt operator/(const BigInt &a,const BigInt &b) { BigInt q,r; dividewithremainder(a,b,q,r); return q; }
BigInt operator%(const BigInt &a,const BigInt &b) { BigInt q,r; dividewithremainder(a,b,q,r); return r; }
BigInt _parse(const string &s,int offset,int k,const vector<BigInt> &xs) {
	if(k==0) return BigInt(0<=offset&&offset<SZ(s)?s[offset]-'0':0);
	return _parse(s,offset,k-1,xs)*xs[k]+_parse(s,offset+(1<<(k-1)),k-1,xs);
}
BigInt parse(const string &s) {
	int k=0; while((1<<k)<SZ(s)) ++k;
	vector<BigInt> xs; xs.PB(BigInt(1)); xs.PB(BigInt(10)); while(k>=SZ(xs)) xs.PB(xs.back()*xs.back());
	return _parse(s,SZ(s)-(1<<k),k,xs);
}
template<typename T> constexpr T constsqr(T a) { return a * a; }
template<typename T> constexpr T constpower(T a, std::size_t n) { return n == 0 ? 1 : constsqr(constpower(a, n / 2)) * (n % 2 == 0 ?  1 : a); }
const int BIGDECIMALDIGITS=9;
const int BIGDECIMALBASE=constpower(10,BIGDECIMALDIGITS);
struct BigDecimal {
	vector<int> d;
	BigDecimal() {}
	BigDecimal(unsigned long long x) { while(x>0) d.PB(x%BIGDECIMALBASE),x/=BIGDECIMALBASE; }
};
BigDecimal& operator+=(BigDecimal &a,const BigDecimal &b) { 
	long long carry=0;
	for(int i=0;i<SZ(b.d)||carry!=0;++i) {
		if(i<SZ(a.d)) carry+=a.d[i]; else a.d.PB(0);
		if(i<SZ(b.d)) carry+=b.d[i];
		a.d[i]=carry%BIGDECIMALBASE; carry/=BIGDECIMALBASE;
	}
	return a;
}
BigDecimal operator+(const BigDecimal &a,const BigDecimal &b) { BigDecimal ret=a; ret+=b; return ret; }
BigDecimal operator*(const BigDecimal &a,const BigDecimal &b) {
	BigDecimal ret;
	for(int j=0;j<SZ(b.d);++j) {
		long long carry=0;
		for(int i=0;i<SZ(a.d)||carry!=0;++i) {
			if(i<SZ(a.d)) carry+=(long long)a.d[i]*b.d[j];
			if(i+j<SZ(ret.d)) carry+=ret.d[i+j]; else ret.d.PB(0);
			ret.d[i+j]=carry%BIGDECIMALBASE; carry/=BIGDECIMALBASE;
		}
	}
	return ret;
}
BigDecimal _format(const BigInt &a,int offset,int k,const vector<BigDecimal> &xs) {
	if(k==0) return BigDecimal(0<=offset&&offset<SZ(a.d)?a.d[offset]:0);
	return _format(a,offset,k-1,xs)*xs[k]+_format(a,offset-(1<<(k-1)),k-1,xs);
}
string format(const BigInt &a) {
	int k=0; while((1<<k)<SZ(a.d)) ++k;
	vector<BigDecimal> xs; xs.PB(BigDecimal(1)); xs.PB(BigDecimal(1LL<<BIGINTBITS)); while(k>=SZ(xs)) xs.PB(xs.back()*xs.back());
	BigDecimal ans=_format(a,(1<<k)-1,k,xs);
	if(SZ(ans.d)==0) return "0";
	string ret(SZ(ans.d)*BIGDECIMALDIGITS,'?');
	REPSZ(i,ans.d) sprintf(&ret[0]+i*BIGDECIMALDIGITS,"%0*d",BIGDECIMALDIGITS,ans.d[SZ(ans.d)-i-1]);
	int nzero=0; while(nzero<SZ(ret)&&ret[nzero]=='0') ++nzero; ret=ret.substr(nzero);
	return ret;
}
BigInt gcd(const BigInt &a,const BigInt &b) {
	return SZ(b.d)==0?a:gcd(b,a%b);
}

void extractleadingbits(const BigInt &p,const BigInt &q,unsigned long long &x,unsigned long long &y) {
	x=(((unsigned long long)p.d[SZ(p.d)-1])<<BIGINTBITS)|p.d[SZ(p.d)-2];
	y=(((unsigned long long)(SZ(q.d)==SZ(p.d)?q.d[SZ(p.d)-1]:0))<<BIGINTBITS)|q.d[SZ(p.d)-2];
	if(SZ(p.d)==2) return; int shift=0; while(((x>>(2*BIGINTBITS-shift-1))&1)==0) ++shift; if(shift==0) return;
	x=(x<<shift)|(p.d[SZ(p.d)-3]>>(BIGINTBITS-shift)),y=(y<<shift)|(q.d[SZ(p.d)-3]>>(BIGINTBITS-shift));
}
BigInt lehmergcd(BigInt p,BigInt q) {
	int cmpres=cmp(p,q); if(cmpres==0) return p; if(cmpres<0) swap(p,q);
	unsigned long long x,y,z,num1,den1,w1,num2,den2,w2,e,f,xn,yn,t; unsigned int a,b,c,d,w; bool needlongdiv; int parity; int nlong=0,nlehmer=0,clehmer,nit=0;
	while(true) {
		if(SZ(q.d)==0) return p; else if(SZ(p.d)<=2) break; else needlongdiv=false;
		if(SZ(p.d)-SZ(q.d)>=2) needlongdiv=true;
		if(!needlongdiv) { extractleadingbits(p,q,x,y); if(y<=BIGINTMASK||x==y) needlongdiv=true; if(x==((((unsigned long long)BIGINTMASK)<<BIGINTBITS)|BIGINTMASK)) x>>=1,y>>=1; }
		if(!needlongdiv) { num1=x,den1=y+1,num2=x+1,den2=y,w1=num1/den1,w2=num2/den2; if(w1!=w2||w1>BIGINTMASK) needlongdiv=true; else w=w1; }
		if(!needlongdiv) { 
			a=0,b=1,c=1,d=w,z=x-w*y,x=y,y=z,parity=0,clehmer=1;
			while(true) {
				if(parity==0) { if(y==d) break; num1=x-a,den1=y+c,num2=x+b,den2=y-d; }
				if(parity==1) { if(y==c) break; num1=x-b,den1=y+d,num2=x+a,den2=y-c; }
				w1=num1/den1,w2=num2/den2; if(w1!=w2||w1>BIGINTMASK) break; else w=w1;
				e=a+w*c,f=b+w*d,z=x-w*y; if(e>BIGINTMASK||f>BIGINTMASK) break; else a=c,c=e,b=d,d=f,x=y,y=z,parity=1-parity,++clehmer;
			}
		}
		if(!needlongdiv&&b!=0) {
			//printf("lehmer step (%s,%s) -> %u %u %u %u (parity=%d)\n",format(p).c_str(),format(q).c_str(),a,b,c,d,parity);
			x=0,y=0,xn=0,yn=0,nlehmer+=clehmer,++nit; while(SZ(q.d)<SZ(p.d)) q.d.PB(0);
			for(int i=0;i<SZ(p.d);++i) {
				unsigned long long cp=p.d[i],cq=q.d[i];
				if(parity==0) x+=cq*b,xn+=cp*a,y+=cp*c,yn+=cq*d; else x+=cp*a,xn+=cq*b,y+=cq*d,yn+=cp*c;
				t=min(x,xn),x-=t,xn-=t,t=min(y,yn),y-=t,yn-=t;
				if(xn==0) p.d[i]=x&BIGINTMASK,x>>=BIGINTBITS; else if((xn&BIGINTMASK)==0) p.d[i]=0,xn>>=BIGINTBITS; else p.d[i]=BIGINTMASK-(xn&BIGINTMASK)+1,xn>>=BIGINTBITS,++xn;
				if(yn==0) q.d[i]=y&BIGINTMASK,y>>=BIGINTBITS; else if((yn&BIGINTMASK)==0) q.d[i]=0,yn>>=BIGINTBITS; else q.d[i]=BIGINTMASK-(yn&BIGINTMASK)+1,yn>>=BIGINTBITS,++yn;
				//if(parity==0) x+=cq*b-cp*a,y+=cp*c-cq*d; else x+=cp*a-cq*b,y+=cq*d-cp*c;
				//p.d[i]=x&BIGINTMASK,x>>=BIGINTBITS,q.d[i]=y&BIGINTMASK,y>>=BIGINTBITS;
			}
			//printf("=> (%s,%s) [%llx,%llx,%llx,%llx]\n",format(p).c_str(),format(q).c_str(),x,y,xn,yn);
			assert(x==0&&y==0&&xn==0&&yn==0); normalize(p); normalize(q);
		} else {
			BigInt r=p%q; p=q,q=r; ++nlong,++nit;
		}
	}
	x=(((unsigned long long)(SZ(p.d)==2?p.d[1]:0))<<BIGINTBITS)|p.d[0];
	y=(((unsigned long long)(SZ(q.d)==2?q.d[1]:0))<<BIGINTBITS)|q.d[0];
	while(y!=0) { z=x%y,x=y,y=z; }
	//printf("nlong=%d nlehmer=%d nit=%d => %.2lf\n",nlong,nlehmer,nit,1.0*nlehmer/(nit-nlong));
	return BigInt(x);
}

int bitcnt(const BigInt &x) { if(SZ(x.d)==0) return 0; int r=0; while(x.d[SZ(x.d)-1]>=(1ULL<<r)) ++r; return (SZ(x.d)-1)*BIGINTBITS+r; }
BigInt randbits(int nbits,mt19937 &rnd) { BigInt ret; int ndigs=(nbits+BIGINTBITS-1)/BIGINTBITS; REP(i,ndigs-1) ret.d.PB(rnd()); ret.d.PB(rnd()%(1ULL<<(nbits-(ndigs-1)*BIGINTBITS))); normalize(ret); return ret; }
BigInt pw(BigInt x,BigInt n,BigInt mod) { BigInt ret(1); REP(i,SZ(n.d)*BIGINTBITS) { if((n.d[i/BIGINTBITS]&(1ULL<<(i%BIGINTBITS)))!=0) ret=ret*x%mod; x=x*x%mod; } return ret; }

bool isprobableprime(const BigInt &n,mt19937 &rnd) {
	if(SZ(n.d)==1&&(n.d[0]==2||n.d[0]==3)) return true; 
	if(SZ(n.d)==0||SZ(n.d)==1&&n.d[0]==1||(n.d[0]&1)==0) return false;
	BigInt d=n-1; int r=0; while(d.d[0]==0) r+=BIGINTBITS,d.d.erase(d.d.begin()); int rr=0; while((d.d[0]&(1<<rr))==0) ++rr; r+=rr; d=d>>rr;
	//printf("%s = %s<<%d+1\n",format(n).c_str(),format(d).c_str(),r);
	BigInt alo=2,ahi=n-2; int ahibits=bitcnt(ahi);
	BigInt xlo=1,xhi=n-1;
	REP(k,4) {
		BigInt a; while(true) { a=randbits(ahibits,rnd); if(alo<=a&&a<=ahi) break; }
		BigInt x=pw(a,d,n);
		//printf("\ta=%s x=%s\n",format(a).c_str(),format(x).c_str());
		if(x==xlo||x==xhi) continue;
		bool ok=false; REP(i,r-1) { x=x*x%n; if(x==xhi) { ok=true; break; } } if(ok) continue;
		return false;
	}
	return true;
}

bool local=false;
vector<BigInt> ploc; BigInt nloc;
mt19937 locrnd;


BigInt egcd(BigInt a, BigInt b, BigInt &x, bool &xneg, BigInt &y, bool &yneg) {
	//printf("egcd(%s,%s)\n",format(a).c_str(),format(b).c_str());
	if (b == 0) { x = 1, xneg = false, y = 0, yneg = false; return a; }
	BigInt g = egcd(b, a%b, y, yneg, x, xneg); BigInt z = x * (a / b); if(xneg != yneg) y += z; else if(z <= y) y -= z; else y = z - y, yneg = !yneg; return g;
}
pair<BigInt, BigInt> invcrt(BigInt a1, BigInt mod1, BigInt a2, BigInt mod2) {
	if(a2<a1) swap(a1,a2),swap(mod1,mod2);
	bool c1neg, c2neg; BigInt c1, c2, g = egcd(mod1, mod2, c1, c1neg, c2, c2neg); assert ((a2 - a1) % g == 0); // printf("here a1=%s a2=%s mod1=%s mod2=%s g=%s c1=%s c2=%s\n",format(a1).c_str(),format(a2).c_str(),format(mod1).c_str(),format(mod2).c_str(),format(g).c_str(),format(c1).c_str(),format(c2).c_str());
	BigInt t = (a2 - a1) / g, lcm = mod1 / g * mod2; if(c1neg) c1 = mod2 - c1; BigInt x = (a1 + c1 * t % (mod2 / g) * mod1) % lcm; return MP(x, lcm);
}
pair<BigInt, BigInt> invcrt(vector<BigInt> a, vector<BigInt> mod) {
	pair<BigInt, BigInt> ret = MP(a[0], mod[0]); FORSZ(i, 1, a) ret = invcrt(ret.first, ret.second, a[i], mod[i]); return ret;
}

BigInt query(BigInt x) {
	if(!local) {
		printf("sqrt %s\n",format(x).c_str()); fflush(stdout);
		string s; cin>>s; assert(s!="-1"); return parse(s);
	} else {
		// y*y=x mod p1*p2*p3*...*pk
		vector<BigInt> a;
		REPSZ(i,ploc) {
			BigInt cx=x%ploc[i];
			BigInt cy=pw(cx,(ploc[i]+1)/4,ploc[i]);
			if(locrnd()%2==1) cy=ploc[i]-cy;
			BigInt A=cy*cy%ploc[i],B=cx;
			//printf("cx=%s cy=%s ploc=%s (%s==%s) %d [%d,%d]\n",format(cx).c_str(),format(cy).c_str(),format(ploc[i]).c_str(),format(cy*cy%ploc[i]).c_str(),format(cx).c_str(),cmp(cy*cy%ploc[i],cx),SZ(A.d),SZ(B.d));
			assert(cy*cy%ploc[i]==cx);
			a.PB(cy);
		}
		BigInt ret=invcrt(a,ploc).first;
		assert(ret*ret%nloc==x);
		return ret;
	}
}

vector<BigInt> ans;

void solve(const string &s) {
	std::mt19937 rnd((int)std::chrono::steady_clock::now().time_since_epoch().count());
	//std::mt19937 rnd(12389);
	BigInt n=parse(s);
	//state: n=a1*a2*...*ak
	ans.clear();
	vector<BigInt> comp; comp.PB(n);
	while(SZ(comp)>0) {
		// choose random x < n
		BigInt x;
		while(true) { x.d.clear(); REP(i,SZ(n.d)-1) x.d.PB(rnd()); int mxbit=0; while(n.d[SZ(n.d)-1]>=(2ULL<<mxbit)) ++mxbit; x.d.PB(rnd()%(2ULL<<mxbit)); normalize(x); if(x<n) break; }
		//printf("x=%s\n",format(x).c_str());
		
		// calculate y=x^2 and ask for z=sqrt(y) until z!=+-x
		BigInt y=x*x%n;
		BigInt z=query(y);
		if(z==x||z==n-x) continue;
		
		//then (x-z)(x+z)=x^2-z^2=0 and therefore x-z and x+z are divisors of n
		BigInt d=(x+z)%n; 
		//printf("x=%s z=%s n=%s d=%s\n",format(x).c_str(),format(z).c_str(),format(n).c_str(),format(d).c_str());
		//BigInt dd=x<=z?z-x:x-z; printf("%s / %s -> %s * %s = %s (%s)\n",format(x*x%n).c_str(),format(z*z%n).c_str(),format(d).c_str(),format(dd).c_str(),format(d*dd%n).c_str(),format(n%d).c_str());
		vector<BigInt> ncomp;
		REPSZ(i,comp) { BigInt g=lehmergcd(comp[i],d); if(g==1||g==comp[i]) ncomp.PB(comp[i]); else { BigInt gg=comp[i]/g; (isprobableprime(g,rnd)?ans:comp).PB(g),(isprobableprime(gg,rnd)?ans:comp).PB(gg); } }
		comp=ncomp;
		//printf("y=%s\n",format(y).c_str());
		//printf("z=%s\n",format(z).c_str());
		
	}
	sort(ans.begin(),ans.end());
	//printf("ans:"); REPSZ(i,ans) printf(" %s",format(ans[i]).c_str()); puts("");
}


void run() {
	string s; cin>>s;
	solve(s);
	printf("! %d",SZ(ans)); REPSZ(i,ans) printf(" %s",format(ans[i]).c_str()); fflush(stdout);
}

void stressdivsmall() {
	printf("\nstressdivsmall\n");
	REP(rep,1000000) {
		int ydig=rand()%32+1; unsigned long long y=0; REP(i,ydig) y=(y<<1)+rand()%2; if(y==0) continue;
		int xdig=rand()%(2*ydig)+1; unsigned long long x=0; REP(i,xdig) x=(x<<1)+rand()%2;
		BigInt a(x),b(y),c=a/b;
		unsigned long long have=c.val(),want=x/y;
		if(have==want) { if(rep%1000==999) printf("."); continue; }
		printf("rep%d: %llu/%llu -> have=%llu want=%llu\n",rep,x,y,have,want); break;		
	}
}

void stressdivlarge() {
	printf("\nstressdivlarge\n");
	REP(rep,1000) {
		BigInt a; a.d.resize((1000+BIGINTBITS-1)/BIGINTBITS); REPSZ(i,a.d) REP(j,BIGINTBITS) a.d[i]|=(rand()%2)<<j; normalize(a);
		BigInt b; b.d.resize((SZ(a.d)+1)/2); REPSZ(i,b.d) REP(j,BIGINTBITS) b.d[i]|=(rand()%2)<<j; normalize(b); if(SZ(b.d)==0) continue;
		//printf("%d and %d %llu and %llu\n",SZ(a.d),SZ(b.d),a.val(),b.val());
		BigInt c=a/b;
		BigInt d=a-b*c;
		if(d<b) { printf("."); continue; }
		printf("err\n");
	}
}

void stressparse() {
	printf("\nverifying small\n");
	REP(rep,100) {
		int len=rand()%18+1; string s(len,'?'); REP(i,len) s[i]='0'+rand()%10; while(SZ(s)>1&&s[0]=='0') s=s.substr(1);
		BigInt a=parse(s);
		unsigned long long havenum=a.val(),wantnum; sscanf(s.c_str(),"%llu",&wantnum);
		if(havenum!=wantnum) {
			printf("err %s => havenum=%llu wantnum=%llu\n",s.c_str(),havenum,wantnum); return;
		}
		string havestr=format(a),wantstr=s;
		if(havestr!=wantstr) {
			printf("err %s => havestr=%s wantstr=%s\n",s.c_str(),havestr.c_str(),wantstr.c_str()); return;
		}
		printf(".");
	}
	printf("\ntesting large\n");
	REP(rep,100) {
		int len=10000; string s(len,'?'); REP(i,len) s[i]='0'+rand()%10; while(SZ(s)>1&&s[0]=='0') s=s.substr(1);
		BigInt a=parse(s);
		string have=format(a);
		if(have==s) { printf("."); continue; }
		printf("err\n"); break;
	}
}

void stressgcd() {
	printf("\nstressgcdsmall\n");
	/*REP(rep,100000) {
		int xdig=rand()%64+1; unsigned long long x=0; REP(i,xdig) x=(x<<1)+rand()%2;
		int ydig=rand()%64+1; unsigned long long y=0; REP(i,ydig) y=(y<<1)+rand()%2;
		BigInt a(x),b(y),c=gcd(a,b);
		unsigned long long have=c.val(),want=gcd(x,y);
		if(have==want) { if(rep%1000==999) printf("."); continue; }
		printf("rep%d: gcd(%llu,%llu) -> have=%llu want=%llu\n",rep,x,y,have,want); break;		
	}*/
	/*REP(rep,1000000) {
		int xdig=rand()%64+1; unsigned long long x=0; REP(i,xdig) x=(x<<1)+rand()%2;
		int ydig=rand()%64+1; unsigned long long y=0; REP(i,ydig) y=(y<<1)+rand()%2;
		BigInt a(x),b(y),c=lehmergcd(a,b);
		unsigned long long have=c.val(),want=gcd(x,y);
		if(have==want) { if(rep%1000==999) printf("."); continue; }
		printf("rep%d: gcd(%llu,%llu) -> have=%llu want=%llu\n",rep,x,y,have,want); break;		
	}*/
	printf("\nstressgcdlarge lehmer\n");
	REP(rep,100000) {
		BigInt a; a.d=vector<unsigned int>(300,0); REPSZ(i,a.d) REP(j,BIGINTBITS) a.d[i]|=(rand()%2)<<j; normalize(a);
		BigInt b; b.d=vector<unsigned int>(300,0); REPSZ(i,b.d) REP(j,BIGINTBITS) b.d[i]|=(rand()%2)<<j; normalize(b);
		//REP(i,10) { int mlt=rand()%1000*1000+rand()%1000+1; if(rand()%2==1) a=a*mlt; if(rand()%2==1) b=b*mlt; }
		BigInt c=lehmergcd(a,b);
		BigInt d=gcd(a,b); if(format(c)!=format(d)) { printf("err\n"); }
		if(rep%1000==999) printf(".");
		//printf("%s",format(c).c_str());
	}
	/*printf("\nstressgcdlarge stupid\n");
	REP(rep,20) {
		BigInt a; a.d=vector<unsigned int>(1000,0); REPSZ(i,a.d) REP(j,BIGINTBITS) a.d[i]|=(rand()%2)<<j; normalize(a);
		BigInt b; b.d=vector<unsigned int>(1000,0); REPSZ(i,b.d) REP(j,BIGINTBITS) b.d[i]|=(rand()%2)<<j; normalize(b);
		BigInt c=gcd(a,b);
		printf(".");
		printf("%s",format(c).c_str());
	}*/
}


void stressmillerrabin() {
	std::mt19937 rnd(123);
	REP(rep,1000) {
		BigInt n=rnd()%1000; int nbits=rnd()%200; REP(i,nbits) n=n<<1; n=n+1;
		if(isprobableprime(n,rnd)) printf("%s is prime\n",format(n).c_str());
	}
}

void test() {
	local=true;
	locrnd=mt19937(21312);
	int np; scanf("%d",&np);
	ploc.clear(); REP(i,np) { string s; cin>>s; BigInt p=parse(s); assert(isprobableprime(p,locrnd)); ploc.PB(p); }
	sort(ploc.begin(),ploc.end());
	nloc=1; REPSZ(i,ploc) nloc=nloc*ploc[i];
	printf("n=%s\n",format(nloc).c_str());
	REP(rep,100) {
		solve(format(nloc));
		assert(ploc==ans);
		printf(".");
	}
}

void stress() {
	local=true;
	int targetbits=1024;
	locrnd=mt19937(21312);
	REP(rep,1000) {
		nloc=BigInt(1); ploc.clear();
		int nprime=locrnd()%(10-2+1)+2;
		REP(i,nprime) {
			int mxpbits=targetbits/(i+1); BigInt p;
			while(true) {
				BigInt x=randbits(locrnd()%(mxpbits-2)+1,locrnd); p=4*x+3;
				//printf(".");
				bool have=false; REPSZ(j,ploc) if(ploc[j]==p) have=true; if(have) continue;
				if(isprobableprime(p,locrnd)) break;
			}
			//printf("p=%s\n",format(p).c_str());
			nloc=nloc*p; ploc.PB(p);
		}
		sort(ploc.begin(),ploc.end());
		//if(rep==0) { nloc=BigInt(597); ploc.clear(); ploc.PB(3); ploc.PB(199); }
		//printf("est bits in nloc: %d\n",bitcnt(nloc));
		printf("n=%s\n",format(nloc).c_str());
		solve(format(nloc));
		assert(ploc==ans);
	}
}

int main() {
	run();
	//test();
	//stressdivsmall();
	//stressdivlarge();
	//stressparse();
	//stressgcd();
	//stressmillerrabin();
	//stress();
	return 0;
}