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

int N,L;
string words[MAXN];
char A[MAXN];

int main()
{
	int i,j,k,p=1;
	scanf("%d",&N);
	for (i=1;i<=N;i++){
		scanf("%s",A); words[i] = A;
	}
	scanf("%s",A+1); L = strlen(A+1);
	for (i=1;i<=N+1;i++){
		while (p <= L && A[p] != '<') p++;
		if (p > L) break; p++;
		while (p <= L && A[p] != '3') p++;
		if (p > L) break; p++;
		if (i > N) continue;
		for (j=0;j<sz(words[i]);j++){
			while (p <= L && A[p] != words[i][j]) p++;
			if (p > L) break;
			p++;
		}
		if (j < sz(words[i])) break;
	}
	puts(i<=N+1?"no":"yes");
}