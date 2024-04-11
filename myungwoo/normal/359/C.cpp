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

const int MOD = 1e9+7;
int N,X,A[MAXN],ans;
lld sum,C;
map <lld,int> cnt;

int main()
{
    int i; lld x;
    scanf("%d%d",&N,&X);
    for (i=1;i<=N;i++) scanf("%d",A+i), sum += A[i];
    for (i=1;i<=N;i++){
        x = sum-A[i];
        while (++cnt[x] == X) cnt.erase(x++);
    }
    C = min(sum,cnt.begin()->first);
    for (ans=1,x=X;C;C>>=1,x=x*x%MOD) if (C&1) ans = x*ans%MOD;
    printf("%d\n",ans);
}