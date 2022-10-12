#define DEBUG 0

#include <algorithm>
#include <functional>
#include <numeric>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <sstream>
using namespace std;

#define LL long long
#define LD long double
#define PR pair<int,int>

#define Fox(i,n) for (i=0; i<n; i++)
#define Fox1(i,n) for (i=1; i<=n; i++)
#define FoxI(i,a,b) for (i=a; i<=b; i++)
#define FoxR(i,n) for (i=(n)-1; i>=0; i--)
#define FoxR1(i,n) for (i=n; i>0; i--)
#define FoxRI(i,a,b) for (i=b; i>=a; i--)
#define Foxen(i,s) for (i=s.begin(); i!=s.end(); i++)
#define Min(a,b) a=min(a,b)
#define Max(a,b) a=max(a,b)
#define Sz(s) int((s).size())
#define All(s) (s).begin(),(s).end()
#define Fill(s,v) memset(s,v,sizeof(s))
#define pb push_back
#define mp make_pair
#define x first
#define y second

template<typename T> T Abs(T x) { return(x<0 ? -x : x); }
template<typename T> T Sqr(T x) { return(x*x); }
string plural(string s) { return(Sz(s) && s[Sz(s)-1]=='x' ? s+"en" : s+"s"); }

const int INF = (int)1e9;
const LD EPS = 1e-12;
const LD PI = acos(-1.0);

//#if DEBUG
#define GETCHAR getchar
/*#else
#define GETCHAR getchar_unlocked
#endif*/

bool Read(int &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

bool ReadLL(LL &x)
{
	char c,r=0,n=0;
	x=0;
		for(;;)
		{
			c=GETCHAR();
				if ((c<0) && (!r))
					return(0);
				if ((c=='-') && (!r))
					n=1;
				else
				if ((c>='0') && (c<='9'))
					x=x*10+c-'0',r=1;
				else
				if (r)
					break;
		}
		if (n)
			x=-x;
	return(1);
}

#define MOD 1000000007
#define LIM 530005

typedef long double T_DOUBLE; // May be changed to double for more speed and less precision

struct cpx
{
  cpx(){}
  cpx(T_DOUBLE aa):a(aa),b(0){}
  cpx(T_DOUBLE aa, T_DOUBLE bb):a(aa),b(bb){}
  T_DOUBLE a;
  T_DOUBLE b;
  T_DOUBLE modsq(void) const
  {
    return a * a + b * b;
  }
  cpx bar(void) const
  {
    return cpx(a, -b);
  }
};

cpx operator +(cpx a, cpx b)
{
  return cpx(a.a + b.a, a.b + b.b);
}

cpx operator *(cpx a, cpx b)
{
  return cpx(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a);
}

cpx operator /(cpx a, cpx b)
{
  cpx r = a * b.bar();
  return cpx(r.a / b.modsq(), r.b / b.modsq());
}

cpx EXP(T_DOUBLE theta)
{
  return cpx(cos(theta),sin(theta));
}

const T_DOUBLE two_pi = 4 * acos((T_DOUBLE)0);

// in:     input array
// out:    output array
// step:   {SET TO 1} (used internally)
// size:   length of the input/output {MUST BE A POWER OF 2}
// dir:    either plus or minus one (direction of the FFT)
// RESULT: out[k] = \sum_{j=0}^{size - 1} in[j] * exp(dir * 2pi * i * j * k / size)
void FFT(cpx *in, cpx *out, int step, int size, int dir)
{
  if(size < 1) return;
  if(size == 1)
  {
    out[0] = in[0];
    return;
  }
  int half = size >> 1;
  FFT(in, out, step * 2, half, dir);
  FFT(in + step, out + half, step << 1, half, dir);
  for(int i = 0 ; i < half ; i++)
  {
    cpx even = out[i];
    cpx odd = out[i + half];
    out[i] = even + EXP(dir * two_pi * i / size) * odd;
    out[i + half] = even + EXP(dir * two_pi * (i + half) / size) * odd;
  }
}

// f:      input array f
// g:      input array g
// h:      output array h
// size:   length of f/g/h {MUST BE A POWER OF 2}
// RESULT: h[i] = sum of f[k]*g[i-k] for k=0..(size-1)
// Note: f and g are cyclic (e.g. f[-1] = f[size-1]), so they may be padded
// the right with zeroes to instead compute an acyclic convolution.
void FFTConvolution(cpx *f, cpx *g, cpx *h, int size)
{
  cpx *F = new cpx[size], *G = new cpx[size], *H = new cpx[size];
  FFT(f, F, 1, size, 1);
  FFT(g, G, 1, size, 1);
  for (int i = 0; i < size; i++) H[i] = F[i] * G[i];
  FFT(H, h, 1, size, -1);
  for (int i = 0; i < size; i++) h[i] = h[i] / size;
  delete [] F;
  delete [] G;
  delete [] H;
}

int sz;
LL P[LIM],L[LIM],R[LIM];
cpx f[LIM],g[LIM],h[LIM];

LL Comp(LL x)
{
	x--;
	return(x*(x+1)/2);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z,d;
	Read(N),Read(K);
	//N=20000,K=1;
	M=0;
		Fox(i,N)
		{
			int v;
			Read(v);
			//v=rand()%1000 ? 0 : 1;
				if (v<K)
					P[M++]=i;
		}
		Fox(i,M)
		{
			L[i]=i ? P[i]-P[i-1] : P[i]+1;
			R[i]=i+1<M ? P[i+1]-P[i] : N-P[i];
		}
	LL ans=0;
		if (!M)
			ans=Comp(N+1);
		else
		{
				Fox(i,M)
					ans+=Comp(L[i]);
			ans+=Comp(R[M-1]);
		}
	cout << ans << ' ';
		for(sz=1;sz<M;sz<<=1);
	sz<<=1;
		Fox(i,M)
		{
			f[i]=R[i];
			g[(sz-i)%sz]=L[i];
		}
	FFTConvolution(f,g,h,sz);
		Fox(d,N)
		{
			ans=d<M ? h[d].a+0.5 : 0;
			cout << ans << ' ';
				if (DEBUG)
				{
					LL cor=0;
						Fox(i,M-d+1)
							cor+=L[i]*R[i+d];
						if (cor!=ans)
						{
							cout << "SHOULD BE " << cor << endl;
							break;
						}
				}
		}
	printf("\n");
	return(0);
}

// A[d] = sum{ L[i]*R[i+d] }
// A[d] = sum{ R[i]*L[i-d] }
// H[d] = sum{ F[i]*G[d-i] }