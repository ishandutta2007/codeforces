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

#pragma comment(linker,"/STACK:33554432")

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

int N,A[MAXN],B[MAXN],S[MAXN],ans;

int main()
{
	int i,j,sum=0;
	scanf("%d",&N);
	for (i=1;i<=N;i++) scanf("%d",A+i), S[i] = S[i-1]+A[i];
	for (i=1;i<=N;i++) scanf("%1d",B+i);
	for (i=N;i;i--) if (B[i]){
		put_max(ans,sum+S[i-1]);
		sum += A[i];
	}
	put_max(ans,sum);
	printf("%d\n",ans);
}