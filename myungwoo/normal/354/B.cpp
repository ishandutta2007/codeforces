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
typedef long long lld;
typedef pair<int,int> pii;

int N;
int D[40][1<<20];
char A[20][21];

int dy(int s,int msk)
{
	int &ret = D[s][msk];
	if (ret > -2e9) return ret;
	int y;
	for (y=0;!(msk&(1<<y));y++);
	ret = (A[y][s-y] == 'b') - (A[y][s-y] == 'a');
	if (s&1) ret = -ret;
	if (s == N+N-2) return ret;
	int best = -2e9;
	for (char ch='a';ch<='z';ch++){
		int nmsk=0,i;
		for (i=0;i<N;i++) if (msk&(1<<i)){
			if (s-i+1 < N && A[i][s-i+1] == ch) nmsk |= (1<<i);
			if (i+1 < N && A[i+1][s-i] == ch) nmsk |= (1<<(i+1));
		}
		if (!nmsk) continue;
		put_max(best,-dy(s+1,nmsk));
	}
	ret += best;
	return ret;
}

int main()
{
	int i,j,k;
	scanf("%d",&N);
	for (i=0;i<N;i++) scanf("%s",A[i]);
	for (i=0;i<N+N;i++) for (j=0;j<(1<<N);j++) D[i][j] = -2e9;
	k = -dy(0,1);
	if (k > 0) puts("FIRST");
	else if (!k) puts("DRAW");
	else puts("SECOND");
}