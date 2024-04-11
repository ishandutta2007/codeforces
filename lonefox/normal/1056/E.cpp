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

#define TEST 0

//#define MOD 1000000007
#define LIM 1000005

LL BASES[5]={10007,11003,12007,13001,14009};
LL MODS[5]={1000000007,1000000103,1000000207,1000000321,1000000403};

LL BASE,MOD;
LL basePow[LIM],baseInv[LIM];

int C[2],L[2];
char S[LIM],T[LIM];
bool vis[2];
char P[2][LIM];
LL H[2];
LL PH[LIM];

PR gcd(int a,int b)
{
		if (!b)
			return(mp(1,0));
	PR p=gcd(b,a%b);
	return(mp(p.y,p.x-(a/b)));
}

LL Inv(LL b)
{
	LL inv=gcd(b,MOD).x;
		if (inv<0)
			inv+=MOD;
	return(inv);
}

void DoSet(int k,int a)
{
	int j;
		if (TEST)
		{
			Fox(j,L[k])
				P[k][j]=T[a++];
			return;
		}
	int b=a+L[k];
	LL h=PH[b];
	h-=PH[a]*basePow[L[k]]%MOD;
	h=(h%MOD+MOD)%MOD;
	H[k]=h;
}

bool IsVal(int k,int a)
{
	int j;
		if (TEST)
		{
				Fox(j,L[k])
					if (P[k][j]!=T[a++])
						return(0);
			return(1);
		}
	int b=a+L[k];
	LL h=PH[b];
	h-=PH[a]*basePow[L[k]]%MOD;
	h=(h%MOD+MOD)%MOD;
	return(H[k]==h);
}

bool Diff()
{
	int i;
		if (TEST)
		{
				Fox(i,L[0])
					if (P[0][i]!=P[1][i])
						return(1);
			return(0);
		}
	return(H[0]!=H[1]);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int N,M,K;
	int i,j,k,a,b,c,x,y,z,v,t;
	scanf("%s%s",&S,&T);
	N=strlen(S);
		Fox(i,N)
			C[S[i]-'0']++;
	M=strlen(T);
	/*M=1000;
		Fox(i,M)
			T[i]='x';
	T[10]='y';*/
	//hashing
	srand(time(NULL));
	BASE=BASES[rand()%5];
	MOD=MODS[rand()%5];
	basePow[0]=1;
		Fox1(i,M+1)
			basePow[i]=basePow[i-1]*BASE%MOD;
		/*Fox(i,M+2)
			baseInv[i]=Inv(basePow[i]);*/
	PH[0]=0;
		Fox(i,M)
			PH[i+1]=(PH[i]*BASE + T[i]-'a')%MOD;
	//do it
	int ans=0;
		Fox1(L[0],M-1)
		{
			LL s=(LL)C[0]*L[0];
				if (s>=M)
					break;
				if ((M-s)%C[1])
					continue;
			L[1]=(M-s)/C[1];
			j=0;
			Fill(vis,0);
				Fox(i,N)
				{
					k=S[i]-'0';
						if (!vis[k])
						{
							vis[k]=1;
							DoSet(k,j);
						}
						else
						if (!IsVal(k,j))
							goto Bad;
					j+=L[k];
				}
				if (L[0]==L[1])
					if (!Diff())
						goto Bad;
			ans++;
Bad:;
		}
End:;
	printf("%d\n",ans);
	return(0);
}