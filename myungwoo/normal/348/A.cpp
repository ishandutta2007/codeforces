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

#define MAXN 100005

int N,A[MAXN],ans;

bool proc(int m)
{
	int i;
	lld sum=0;
	for (i=1;i<=N;i++) if (A[i] > m) return 0;
	for (i=1;i<=N;i++) sum += m-A[i];
	return sum >= m;
}

int main()
{
	int i;
	scanf("%d",&N);
	for (i=1;i<=N;i++) scanf("%d",A+i);
	lld s=1,e=2e9,m;
	while (s <= e){
		m = (s+e)>>1;
		if (proc(m)) e = m-1, ans = m;
		else s = m+1;
	}
	printf("%d\n",ans);
}