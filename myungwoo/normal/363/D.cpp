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

int N,M,C,ans,ans2;
int A[MAXN],P[MAXN];

bool proc(int m)
{
	int i,j,sum=0;
	for (i=m,j=N;i;i--,j--){
		if (A[j] < P[i]){
			sum += P[i]-A[j];
			if (sum > C) return 0;
		}
	}
	return 1;
}

int main()
{
	int i,j,k;
	scanf("%d%d%d",&N,&M,&C);
	for (i=1;i<=N;i++) scanf("%d",A+i);
	for (i=1;i<=M;i++) scanf("%d",P+i);
	sort(A+1,A+N+1); sort(P+1,P+M+1);
	int s=1,e=min(N,M),m;
	while (s <= e){
		m = (s+e)>>1;
		if (proc(m)) s = m+1, ans = m;
		else e = m-1;
	}
	for (i=ans,j=N;i;i--,j--){
		if (A[j] < P[i]) C -= P[i]-A[j], ans2 += A[j];
		else ans2 += P[i];
	}
	printf("%d %d\n",ans,max(0,ans2-C));
}