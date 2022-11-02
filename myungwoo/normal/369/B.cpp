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

int N,K,L,R,all,top;
vector <int> ans;

int main()
{
	int i;
	cin >> N >> K >> L >> R >> all >> top;
	if (K < N){
		int p = (all-top)/(N-K);
		for (i=1;i<=N-K;i++){
			if (i <= (all-top)%(N-K)) ans.pb(p+1);
			else ans.pb(p);
		}
	}
	sort(all(ans));
	int last = ans.empty()?L:ans.back();
	for (i=K;i--;){
		int sc = max(last,top-i*R);
		last = sc;
		ans.pb(sc);
		top -= sc;
	}
	for (i=0;i<sz(ans);i++) printf("%d ",ans[i]); puts("");
}