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

#define MAXN 200005

int N,K,A[MAXN];
vector <int> ans;

int main()
{
    int i,n=0;
    lld sum=0;
    scanf("%d%d",&N,&K);
    for (i=1;i<=N;i++) scanf("%d",A+i);
    for (i=1;i<=N;i++){
        if (sum-lld(N-i)*n*A[i] < K){ ans.pb(i); continue; }
        sum += lld(n)*A[i]; n++;
    }
    for (i=0;i<sz(ans);i++) printf("%d\n",ans[i]);
}