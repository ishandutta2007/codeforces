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

int N,A[1004];

int main()
{
	int i,j;
	scanf("%d",&N);
	if (N == 1){ puts("no"); return 0; }
	for (i=1;i<=N;i++){
		scanf("%d",A+i);
		for (j=2;j<i;j++){
			int s=A[j-1],e=A[j];
			if (s > e) swap(s,e);
			if (s < A[i-1] && A[i-1] < e && (s > A[i] || e < A[i]) ||
				s < A[i] && A[i] < e && (s > A[i-1] || e < A[i-1])) break;
		}
		if (j < i) break;
	}
	puts(i <= N ? "yes" : "no");
}