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

#define MAXN 200005

int N,M;
bool del[MAXN];
char A[MAXN],B[MAXN];

int main()
{
	int i,j,k,cnt=0;
	scanf("%s",A); N = strlen(A);
	for (i=0;i<N;i++){
		if (!i || A[i-1] != A[i]) cnt = 0;
		cnt++;
		if (cnt >= 3) del[i] = 1;
	}
	for (i=0;i<N;i++) if (!del[i]) B[M++] = A[i];
	set(del,0);
	cnt = 0; int prev = 0;
	for (i=0;i<M;i++){
		if (!i || B[i-1] != B[i]) prev = cnt, cnt = 0;
		cnt++;
		if (cnt == 2 && prev == 2) del[i] = 1, cnt--;
	}
	for (i=0;i<M;i++) if (!del[i]) printf("%c",B[i]); puts("");
}