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

int N,A[2002],ans;

int main()
{
	int i,j,k;
	scanf("%d",&N);
	for (i=1;i<=N;i++) scanf("%d",A+i), A[i] = abs(A[i]);
	for (i=1;i<=N;i++){
		int a=0,b=0;
		for (j=1;j<=N;j++) if (A[j] < A[i]){
			if (j < i) a++;
			else b++;
		}
		ans += min(a,b);
	}
	printf("%d\n",ans);
}