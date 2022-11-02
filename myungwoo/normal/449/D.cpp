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
#define add(target,value,mod) target = (target+(value))%(mod)
#define put_min(target,value) target = min(target,value)
#define put_max(target,value) target = max(target,value)
typedef long long lld;
typedef pair<int,int> pii;
typedef pair<lld,int> pli;
typedef pair<int,lld> pil;
typedef pair<lld,lld> pll;

#define MAXN 1048576
#define bit(n) (1<<(n))

const int MOD = 1e9 + 7;
int N,A[MAXN],P[MAXN]={1},ans;

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for (i=1;i<=N;i++){
        scanf("%d",&k), A[k]++;
        P[i] = P[i-1]<<1;
        if (P[i] >= MOD) P[i] -= MOD;
    }
    for (j=0;j<20;j++){
        for (i=bit(20);--i;) if (i&bit(j)){
            k = i^bit(j);
            A[k] += A[i];
            if (A[k] >= MOD) A[k] -= MOD;
        }
    }
    for (i=0;i<bit(20);i++){
        int cnt=0,v=P[A[i]];
        for (j=0;j<20;j++) if (i&bit(j)) cnt++;
        if (cnt&1){
            ans -= v;
            if (ans < 0) ans += MOD;
        }
        else{
            ans += v;
            if (ans >= MOD) ans -= MOD;
        }
    }
    printf("%d\n",ans);
}