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

#define MAXN 2002

const int MOD = 1e9+7;
int N,K,D[MAXN][MAXN][2],ans;
char A[MAXN];
vector <int> con[MAXN];

int main()
{
	int i,j,k,t;
	scanf("%d%d%s",&N,&K,A+1);
	for (i=1;i<N;i++) for (j=i+1;j<=N;j++){
		if ((j-i)*(N-j+1) <= K) con[i].push_back(j);
	}
	for (i=1;i<=N;i++){
		k = A[i]-'a';
		if (i*(N-i+1) <= K) D[i][i*(N-i+1)][0] = 26-k-1;
	}
	D[1][0][1] = 1;
	D[1][0][0] = A[1]-'a';
	for (i=1;i<N;i++) for (j=0;j<=K;j++) if (D[i][j]){
		add(D[i+1][j][0],(lld)(D[i][j][0]+D[i][j][1])*(A[i+1]-'a'),MOD);
		add(D[i+1][j][1],(D[i][j][0]+D[i][j][1])%MOD,MOD);
		for (k=con[i].size();k--;){
			t = con[i][k];
			if (j+(t-i)*(N-t+1) <= K) add(D[t][j+(t-i)*(N-t+1)][0],(lld)D[i][j][0]*(26-(A[t]-'a')-1),MOD);
		}
	}
	printf("%d\n",(D[N][K][0]+D[N][K][1])%MOD);
}