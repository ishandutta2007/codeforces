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

#define MAXN 109

int P,Q,N,M,ans;
char A[MAXN],B[MAXN];
int V[MAXN];

int main()
{
	int i,j;
	scanf("%d%d%s%s",&P,&Q,A,B);
	N = strlen(A), M = strlen(B);
	for (i=0;i<M;i++) for (j=0;j<N;j++){
		if (A[j] == B[(i+V[i])%M]) V[i]++;
	}
	for (i=0;i<P;i++) ans += V[ans%M];
	printf("%d\n",ans/Q/M);
}