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
const LD EPS = 1e-9;
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

int L;
LL ansV=-1;
LL ansC;
int N[2];
int V[2][100000];

void Go30(int a)
{
		if (N[a]<3)
			return;
	LL v=(LL)2*(V[a][N[a]-1]-V[a][0]);
		if (v<ansV)
			return;
		if (v>ansV)
			ansC=0,ansV=v;
	LL c;
		if (!v)
			c=(LL)N[a]*(N[a]-1)*(N[a]-2)/6;
		else
		{
			int i,c1,c2,c3;
			c1=0,i=0;
				while (V[a][i]==V[a][0])
					i++,c1++;
			c2=0,i=N[a]-1;
				while (V[a][i]==V[a][N[a]-1])
					i--,c2++;
			c3=N[a]-c1-c2;
			c=(LL)c1*c2*c3 + (LL)c1*(c1-1)*c2/2 + (LL)c2*(c2-1)*c1/2;
		}
	ansC+=c;
}

void Gooo(int a,int bv)
{
	/*int j,k;
	int vv=-1;
	vector <PR> lst;
		Fox(j,N[a]-1)
			FoxI(k,j+1,N[a]-1)
			{
				int a1=V[a][j];
				int a2=V[a][k];
				int v=abs(a1-a2) + 2*L - abs(a1-bv) - abs(a2-bv);
					if (v<vv)
						continue;
					if (v>vv)
						lst.clear(),vv=v;
				lst.pb(mp(a1,a2));
					if (v<ansV)
						continue;
					if (v>ansV)
						ansC=0,ansV=v;
				ansC++;
			}
	int i;
		Fox(i,N[a])
			printf("%d ",V[a][i]);
	printf("\n");
	printf("%d\n",bv);
		Fox(i,Sz(lst))
			printf("%d %d\n",lst[i].x,lst[i].y);
	printf("\n\n");*/
	LL v;
	int a1,a2;
	LL c;
		if (bv<V[a][0])
		{
			a1=V[a][0];
			int i=upper_bound(V[a],V[a]+N[a],a1) - lower_bound(V[a],V[a]+N[a],a1);
			int j=N[a]-i;
			a2=V[a][1];
			v=abs(a1-a2) + (LL)2*L - abs(a1-bv) - abs(a2-bv);
			c=(LL)i*j + (LL)i*(i-1)/2;
		}
		else
		if (bv>V[a][N[a]-1])
		{
			a1=V[a][N[a]-1];
			int i=upper_bound(V[a],V[a]+N[a],a1) - lower_bound(V[a],V[a]+N[a],a1);
			int j=N[a]-i;
			a2=V[a][0];
			v=abs(a1-a2) + (LL)2*L - abs(a1-bv) - abs(a2-bv);
			c=(LL)i*j + (LL)i*(i-1)/2;
		}
		else
		{
			a1=V[a][0];
			a2=V[a][N[a]-1];
			v=abs(a1-a2) + (LL)2*L - abs(a1-bv) - abs(a2-bv);
				if (a1==a2)
					c=(LL)N[a]*(N[a]-1)/2;
				else
				{
					int i,j,k;
					i=lower_bound(V[a],V[a]+N[a],bv)-V[a];
					j=lower_bound(V[a],V[a]+N[a],bv+1)-V[a];
					j=N[a]-j;
					k=upper_bound(V[a],V[a]+N[a],bv) - lower_bound(V[a],V[a]+N[a],bv);
					c=(LL)i*j + (LL)i*k + (LL)k*j + (LL)k*(k-1)/2;
				}
		}
		if (v<ansV)
			return;
		if (v>ansV)
			ansC=0,ansV=v;
	ansC+=c;
}

void Go21(int a,int b)
{
		if ((N[a]<2) || (N[b]<1))
			return;
	int i;
		Fox(i,N[b])
			Gooo(a,V[b][i]);
}

int main()
{
		if (DEBUG)
			freopen("in.txt","r",stdin);
	int M,i,j;
	Read(L),Read(M);
		while (M--)
		{
			Read(i),Read(j);
			V[i][N[i]++]=j;
		}
	sort(V[0],V[0]+N[0]);
	sort(V[1],V[1]+N[1]);
	Go30(0);
	Go30(1);
	Go21(0,1);
	Go21(1,0);
	cout << ansC << endl;
	return(0);
}