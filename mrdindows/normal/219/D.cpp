#include <iostream>
#include <fstream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cmath>
#include<vector>
#include<ctime>
#include<memory.h>
#include<algorithm>
#define sqr(x) ((x)*(x))
#define sqrt(x) sqrt((x)*1.)
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
#define abs(x) ((x)>0?(x):-(x))
#define getar(m,n) for(int _=0;_<n;++_) cin>>(m)[_];
#define fill(m,v) memset(m,v,sizeof(m))
//#define flush {cout.flush();fflush(stdout);}
#define random(x) (((rand()<<15)+rand())%(x))
#define pi 3.1415926535897932
#define y1 stupid_cmath
#define y0 qstupid_cmath_make_me_cry
#define tm stupid_ctime
#define pb push_back
#define mp make_pair
//#define long long long
#include<map>
#include<set>
#include<bitset>
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 using namespace std;

typedef unsigned long long lli;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef pair<int, bool> pii;

const int D=100;


bool *used;
vector<pair<int,bool> > *a;
int *in;
vi q;
int go (int v)
{
	used[v]=true;
	int c=0;
	for (int i=0;i<a[v].size();i++)
	{
		if (!used[a[v][i].first]) 
		{ 
			if (a[v][i].second)
			{
				c+=go(a[v][i].first);
			}
			else
			{
				c+=1+go(a[v][i].first);
			}
		}
	}
	return c;
}
void go2(int v,int c)
{
	if (in[v]<0)
	{
		in[v]=c;
		for (int i=0;i<a[v].size();i++)
		{
			go2(a[v][i].first,c+(a[v][i].second?1:(-1)));
		}
		
	}
}
int main()
{
	int n;
	cin>>n;
	used=new bool[n];
	a=new vector<pair<int,bool> >[n];
	int x,y;
	in=new int[n];
	for (int i=0;i<n;i++)
	{
		used[i]=false;
		in[i]=-1;
	}


	for (int i=0;i<n-1;i++)
	{
		scanf("%d %d",&x,&y);
		x--;y--;
		a[x].push_back(mp(y,true));
		a[y].push_back(mp(x,false));
	}
	int h=go(0);
	go2(0,h);
	int ans=*min_element(in,in+n);
	cout<<ans<<endl;
	for (int i=0;i<n;i++)
	{
		if (in[i]==ans) printf("%d ",i+1);
	}
	cout<<endl;
	return 0;
}