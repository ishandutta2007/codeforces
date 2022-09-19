#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdio>
#include <cctype>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <complex>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cwchar>
#include <cwctype>
#include <exception>
#include <locale>
#include <numeric>
#include <new>
#include <stdexcept>
#include <limits>
#include <valarray>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <list>
#include <utility>
#include <bitset>
#include <algorithm>
#include <functional>
#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<=(n);i++)
#define MP make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
namespace dsu{
	int n,pre[1000005],sz[1000005];
	void clear(int cn){
		n=cn;
		rep1(k,n){
			pre[k]=k;
			sz[k]=1;
		}
	}
	int root(int v){
		return pre[v]==v?v:pre[v]=root(pre[v]);
	}
	ll unite(int u,int v){
		u=root(u);
		v=root(v);
		if(u==v)return 0LL;
		ll ans=ll(sz[u])*sz[v];
		if(sz[u]<sz[v])swap(u,v);
		pre[v]=u;
		sz[u]+=sz[v];
		return ans;
	}
}
int n,num[1000005];
pii E[1000005];
vector<pii> ve[1000005];
void clear(){
	rep1(k,1000000)ve[k].clear();
}
int main(){
	int u,v;
	scanf("%d",&n);
	rep1(k,n)scanf("%d",&num[k]);
	rep(k,n-1){
		scanf("%d%d",&u,&v);
		E[k]=MP(u,v);
	}
	ll ans=0LL;
	dsu::clear(n);
	clear();
	rep(k,n-1)ve[max(num[E[k].first],num[E[k].second])].push_back(E[k]);
	rep1(i,1000000)rep(j,ve[i].size())
	ans+=dsu::unite(ve[i][j].first,ve[i][j].second)*i;
	dsu::clear(n);
	clear();
	rep(k,n-1)ve[min(num[E[k].first],num[E[k].second])].push_back(E[k]);
	for(int i=1000000;i>0;i--)rep(j,ve[i].size())
	ans-=dsu::unite(ve[i][j].first,ve[i][j].second)*i;
	printf("%I64d\n",ans);
	return 0;
}