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

#define MAXN 500005

int N,A[MAXN];
lld S[MAXN],ans;
map <lld,map<lld,int> > cnt;

int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,k;
    cin >> N;
    for (i=1;i<=N;i++) cin >> A[i], S[i] = S[i-1]+A[i];
    for (i=N;--i>1;){
        cnt[S[N]-S[i]][S[i]]++;
        auto &c = cnt[S[i-1]];
        auto it = c.find(2*S[i-1]);
        if (it == c.end()) continue;
        ans += it->second;
    }
    cout << ans << endl;
}