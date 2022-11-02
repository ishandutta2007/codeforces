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

int N,K,D[1001];
struct Z{
    int p[5];
    bool operator < (const Z &ot)const{
        int i;
        for (i=0;i<K;i++) if (p[i] != ot.p[i]) return p[i] < ot.p[i];
        return 0;
    }
} A[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    int i,j,k;
    cin >> N >> K;
    for (i=0;i<K;i++){
        for (j=1;j<=N;j++){
            cin >> k;
            A[k].p[i] = j;
        }
    }
    sort(A+1,A+N+1);
    int ans = 0;
    for (i=1;i<=N;i++){
        D[i] = 1;
        for (j=1;j<i;j++){
            for (k=0;k<K;k++){
                if (A[j].p[k] >= A[i].p[k]) break;
            }
            if (k == K && D[i] < D[j]+1) D[i] = D[j]+1;
        }
        if (ans < D[i]) ans = D[i];
    }
    cout << ans << endl;
}