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

#pragma comment(linker,"/STACK:67108864")

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

#define MAXN 1000006

int N,A[MAXN],S[MAXN];
stack <int> stk;

int main()
{
    int i,k;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",A+i), S[i] = 1;
    for (scanf("%d",&i);i--;) scanf("%d",&k), S[k] = -1;
    for (i=N;i;i--){
        if (S[i] == -1 || stk.empty() || stk.top() != A[i]){
            stk.push(A[i]);
            S[i] = -1;
        }else stk.pop();
    }
    if (stk.empty()){
        puts("YES");
        for (i=1;i<=N;i++) printf("%d ",A[i]*S[i]); puts("");
    }else puts("NO");
}