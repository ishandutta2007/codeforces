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

int N,A[101],B[101],U,D;

int main()
{
	int i,j;
	scanf("%d",&N);
	for (i=1;i<=N;i++) scanf("%d%d",A+i,B+i), U += A[i], D += B[i];
	if (!(U&1) && !(D&1)){ puts("0"); return 0; }
	for (i=1;i<=N;i++){
		if (!((U-A[i]+B[i])&1) && !((D-B[i]+A[i])&1)){ puts("1"); return 0; }
	}
	for (i=1;i<N;i++) for (j=i+1;j<=N;j++){
		if (!((U-A[i]-A[j]+B[i]+B[j])&1) && !((D-B[i]-B[j]+A[i]+A[j])&1)){ puts("2"); return 0; }
	}
	puts("-1");
}