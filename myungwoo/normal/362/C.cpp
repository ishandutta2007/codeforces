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

#define MAXN 5005

int N,A[MAXN],P[MAXN],B[MAXN][MAXN];
int all,ans=2e9,ans2;

int pre(int p,int v){ return (p-1)-B[v-1][p]; }
int post(int p,int v){ return (v-1)-B[v-1][p]; }

int main()
{
	int i,j,k,v=0;
	scanf("%d",&N);
	for (i=1;i<=N;i++) scanf("%d",A+i), ++A[i], P[A[i]] = i;
	for (i=1;i<=N;i++){
		for (j=1;j<=N;j++) B[i][j] = B[i-1][j];
		for (j=P[i];j<=N;j++) B[i][j]++;
	}
	for (i=1;i<=N;i++) all += pre(i,A[i]);
	for (i=1;i<N;i++) for (j=i+1;j<=N;j++) if (A[i] > A[j]){
		int diff = -(pre(i,A[i])+post(i,A[i])+pre(j,A[j])-1+post(j,A[j]));
		diff += pre(i,A[j])+post(i,A[j])+pre(j,A[i])+post(j,A[i]);
		if (ans > all+diff)
			ans = all+diff, ans2 = 0;
		if (ans == all+diff) ans2++;
	}
	printf("%d %d\n",ans,ans2);
}