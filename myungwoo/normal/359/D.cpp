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

#define MAXN 300005

int N,A[MAXN],ans=-1;
vector <int> list;

int main()
{
	int i,r=0;
	scanf("%d",&N);
	for (i=1;i<=N;i++) scanf("%d",A+i);
	for (i=1;i<=N;i++) if (i >= r){
		r = i;
		int l=i;
		while (r <= N && A[r]%A[i] == 0) r++;
		while (l && A[l]%A[i] == 0) l--;
		if (ans < r-l-2)
			ans = r-l-2, list.clear();
		if (ans == r-l-2) list.push_back(l+1);
	}
	printf("%d %d\n",sz(list),ans);
	for (i=0;i<sz(list);i++) printf("%d ",list[i]); puts("");
}