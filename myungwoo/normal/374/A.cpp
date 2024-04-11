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

int N,M,X,Y,A,B;

int dy(int ax,int ay,int bx,int by)
{
    int dx=abs(ax-bx),dy=abs(ay-by);
    if (!dx && !dy) return 0;
    if (bx-A < 1 && bx+A > N || by-B < 1 && by+B > M) return 1e9;
    if (dx%A || dy%B) return 1e9;
    dx /= A, dy /= B;
    if ((dx&1) != (dy&1)) return 1e9;
    return max(dx,dy);
}

int main()
{
    cin >> N >> M >> X >> Y >> A >> B;
    int ans = 1e9;
    put_min(ans,dy(1,1,X,Y));
    put_min(ans,dy(N,1,X,Y));
    put_min(ans,dy(1,M,X,Y));
    put_min(ans,dy(N,M,X,Y));
    if (ans == 1e9) puts("Poor Inna and pony!");
    else printf("%d\n",ans);
}