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

const int MOD = 1e9+7;
int N,M,D[3001][3001],E[3001][3001];
char A[3001][3002];

int main()
{
	int i,j;
	scanf("%d%d",&N,&M);
	for (i=1;i<=N;i++) scanf("%s",A[i]+1);
	if (A[1][2] != '#') D[1][2] = 1;
	if (A[2][1] != '#') E[2][1] = 1;
	for (i=1;i<=N;i++) for (j=1;j<=M;j++){
		if (i < N && A[i+1][j] != '#'){
			add(D[i+1][j],D[i][j],MOD);
			add(E[i+1][j],E[i][j],MOD);
		}
		if (j < M && A[i][j+1] != '#'){
			add(D[i][j+1],D[i][j],MOD);
			add(E[i][j+1],E[i][j],MOD);
		}
	}
	printf("%d\n",((lld)D[N-1][M]*E[N][M-1]%MOD-(lld)E[N-1][M]*D[N][M-1]%MOD+MOD)%MOD);
}