#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back
template <typename T> bool chkmin(T &x,T y){return y<x?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> void readint(T &x)
{
	int f=1;char c;x=0;
	for(c=getchar();!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=x*10+(c-'0');
	x*=f;
}
const int MAXN=200005;

int n,m,r;
bool check(int k)
{
	return (1ll*k*(k-1)*(k-2)/3+1ll*(n-k)*k*(k-1)/2*2+1ll*(n-k)*(n-k-1)/2*k)*r>=1ll*n*(n-1)*(n-2)/3*m;
}

int main()
{
	#ifdef LOCAL
	freopen("code.in","r",stdin);
	#endif
	double p;
	cin>>n>>p;
	r=10000;m=ceil(p*r);
	for(int k=0;k<=n;++k)if(check(k))return 0*printf("%d\n",k);
	return 0;
}