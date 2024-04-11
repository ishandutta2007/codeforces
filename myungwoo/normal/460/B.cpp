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

int A,B,C;
vector <int> ans;

int main()
{
    ios_base::sync_with_stdio(false);
    int s;
    cin >> A >> B >> C;
    for (s=1;s<99;s++){
        lld v = 1;
        for (int i=0;i<A;i++) v *= s;
        lld x = (lld)B*v+C;
        if (x >= 1e9) continue;
        int p = 0;
        for (int t=x;t;t/=10) p += t%10;
        if (s == p) ans.pb(x);
    }
    sort(all(ans));
    cout << sz(ans) << endl;
    for (int x: ans) cout << x << " ";
    cout << endl;
}