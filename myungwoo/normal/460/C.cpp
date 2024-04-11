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

#define MAXN 100005

int N,M,W,A[MAXN];

bool proc(int m)
{
    int i,v=0;
    lld sum = 0;
    queue <pii> que;
    for (i=1;i<=N;i++){
        while (!que.empty() && que.front().first < i) v -= que.front().second, que.pop();
        int d = m>A[i]?m-A[i]:0;
        if (d <= v) continue;
        que.push(mp(i+W-1,d-v));
        sum += d-v;
        v = d;
        if (sum > M) return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int i;
    cin >> N >> M >> W;
    for (i=1;i<=N;i++) cin >> A[i];
    int s = 1, e = 1e9+M, ans;
    while (s <= e){
        int m = (s+e)>>1;
        if (proc(m)) s = m+1, ans = m;
        else e = m-1;
    }
    cout << ans << endl;
}