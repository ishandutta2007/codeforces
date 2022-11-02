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

int N,T[MAXN],from[MAXN];
int out[MAXN],ans;
vector <int> path;

int main()
{
	int i,j,k;
	scanf("%d",&N);
	for (i=1;i<=N;i++) scanf("%d",T+i);
	for (i=1;i<=N;i++) scanf("%d",from+i), out[from[i]]++;
	for (i=1;i<=N;i++) if (T[i]){
		int len=0;
		vector <int> now;
		for (k=i;;){
			len++;
			now.pb(k);
			if (!from[k] || out[from[k]] != 1) break;
			k = from[k];
		}
		if (ans < len) ans = len, path = now;
	}
	printf("%d\n",ans);
	for (i=sz(path);i--;) printf("%d ",path[i]); puts("");
}