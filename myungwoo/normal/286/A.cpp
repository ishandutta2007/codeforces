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

#pragma comment(linker,"/STACK:67108864")

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

int N,A[MAXN];

int main()
{
	int i;
	scanf("%d",&N);
	if (N%4 > 1){ puts("-1"); return 0; }
	if (N&1) A[N/2+1] = N/2+1;
	for (i=1;i<=N/2;i+=2){
		A[i] = i+1, A[i+1] = N-i+1, A[N-i+1] = N-i, A[N-i] = i;
	}
	for (i=1;i<=N;i++) printf("%d ",A[i]); puts("");
}