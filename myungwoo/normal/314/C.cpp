#include <vector>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define same(a,b) (fabs((a)-(b))<eps)
#define set(arr,with) memset(arr,with,sizeof(arr))
#define add(target,value,mod) target = (target+value)%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef pair<int,int> pii;
typedef long long lld;

const int MOD = 1e9+7;
int N,A[1000001],tree[1000001],ans;

int get(int n)
{
	int ret=0;
	for (;n;n-=(n&(-n))) ret = (ret+tree[n])%MOD;
	return ret;
}

void update(int n,int v)
{
	v = (v-A[n]+MOD)%MOD;
	A[n] = (A[n]+v)%MOD;
	for (;n<=1e6;n+=(n&(-n))) tree[n] = (tree[n]+v)%MOD;
}

int main()
{
	int i,k,v;
	scanf("%d",&N);
	for (i=1;i<=N;i++){
		scanf("%d",&k);
		v = (lld(get(k))*k+k)%MOD;
		update(k,v);
	}
	printf("%d\n",get(1e6));
}