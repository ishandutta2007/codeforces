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

int N,X[MAXN],A,B,ans;

int main()
{
    int i;
    scanf("%d",&N);
    for (i=1;i<=N;i++) scanf("%d",X+i);
    sort(X+1,X+N+1);
    N = unique(X+1,X+N+1)-X-1;
    scanf("%d%d",&A,&B);
    while (A > B){
        int nxt = A-1;
        for (i=N;i>0&&X[i]>A-nxt;i--){
            int pos = A-(A%X[i]);
            if (pos >= B && pos < nxt) nxt = pos;
        }
        while (N && A-A%X[N] < B) X[N--] = 0;
        A = nxt;
        ans++;
    }
    printf("%d\n",ans);
}