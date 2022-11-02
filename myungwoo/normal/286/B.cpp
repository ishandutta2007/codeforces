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

#define MAXN 2000006

int N,A[MAXN];

int main()
{
	int i,j,k;
	scanf("%d",&N);
	for (i=1;i<=N;i++) A[i] = i;
	for (i=2;i<=N;i++){
		if (N%i) A[N+i-1] = A[N-N%i+i-1];
		for (j=N/i;j>=0;j--) A[i*(j+1)-1] = A[i*j-1];
	}
	for (i=1;i<=N;i++) printf("%d ",A[i+N-1]); puts("");
}