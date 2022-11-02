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
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 150004
#define MAXM 309

int N,M,K,X[MAXM],T[MAXM];
lld D[2][MAXN],ans,mn;
deque <pli> dq;

int main()
{
    int i,j,k;
    scanf("%d%d%d",&N,&M,&K);
    for (i=1;i<=M;i++){
        scanf("%d%d%d",X+i,&k,T+i);
        ans += k;
    }
    for (i=1;i<=N;i++) D[1][i] = abs(X[1]-i);
    for (i=2;i<=M;i++){
        int t=(i&1);
        lld d = (lld)K*(T[i]-T[i-1]);
        while (!dq.empty()) dq.pop_back();
        for (j=1;j<=N&&j<=d;j++){
            while (!dq.empty() && dq.back().fr >= D[!t][j]) dq.pop_back();
            dq.push_back(mp(D[!t][j],j));
        }
        for (j=1;j<=N;j++){
            while (!dq.empty() && dq.front().sc < j-d) dq.pop_front();
            if (j+d <= N){
                while (!dq.empty() && dq.back().fr >= D[!t][j+d]) dq.pop_back();
                dq.push_back(mp(D[!t][j+d],j+d));
            }
            D[t][j] = dq.front().fr+abs(j-X[i]);
        }
    }
    mn = 1e18;
    for (i=1;i<=N;i++) put_min(mn,D[M&1][i]);
    printf("%lld\n",ans-mn);
}