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

int C1,C2,C3,C4,ans;
int N,M;
int P[1001],Q[1001];

int main()
{
    int i;
    cin >> C1 >> C2 >> C3 >> C4 >> N >> M;
    for (i=1;i<=N;i++) scanf("%d",P+i);
    for (i=1;i<=M;i++) scanf("%d",Q+i);
    ans = C4;
    int sum=0,sum2=0;
    for (i=1;i<=N;i++){
        sum += min(P[i]*C1,C2);
    }
    for (i=1;i<=M;i++){
        sum2 += min(Q[i]*C1,C2);
    }
    put_min(sum,C3);
    put_min(sum2,C3);
    put_min(ans,sum+sum2);
    printf("%d\n",ans);
}