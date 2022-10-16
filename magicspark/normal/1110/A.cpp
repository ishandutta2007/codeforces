#ifdef ONLINE_JUDGE
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize(4)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#pragma GCC optimize("Os")
#pragma GCC optimize("Og")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,sse,sse2,sse3,ssse3,sse4")
#endif
#include <initializer_list>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <queue>
#include <stack>
#include <cmath>
#include <map>
#include <set>
#define pb push_back
#define rep(i,n) for (int i=0;i<(n);++i)
#define rep1(i,n) for (int i=1;i<=(n);++i)
#define Rep(i,a,b) for (int i=(a);i<=(b);++i)
#define All(a) a.begin(),a.end()
#define SZ(a) ((int)a.size())
#define fillset(a,val) memset(a,val,sizeof(a))
#define X first
#define Y second
#define endl '\n'
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int,int> pii;
const int inf=0x3f3f3f3f;
const ll lnf=0x3f3f3f3f3f3f3f3f;
const double EPS=1e-9,PI=acos(-1.0);
const int mod1=1000000007,mod2=998244353;
int b,k,a[100005];
int main()
{
	ios_base::sync_with_stdio(0);
	cin>>b>>k;int ans=0;
	for(int i=0;i<100;i++)rand()*rand()&rand(),cerr<<"okokok";
	for (int i=0;i<k;++i) cin>>a[i];
	for (int i=0;i<k;++i)
		if (i<k-1) ans^=(a[i]*b&1);
		else ans^=a[i];
	printf("%s\n",ans&1?"odd":"even");
	return 0;
}