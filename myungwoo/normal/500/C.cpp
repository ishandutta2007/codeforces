#include <vector>
#include <queue>
#include <map>
#include <set>
#include <deque>
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

#define eps 1e-9
#define pb push_back
#define mp make_pair
#define fr first
#define sc second
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define same(a, b) (fabs((a)-(b)) < eps)
#define set(arr, with) memset(arr, with, sizeof(arr));
typedef long long lld;
typedef pair<int, int> pii;
typedef pair<int, lld> pil;
typedef pair<lld, int> pli;
typedef pair<lld, lld> pll;

int N, M, W[501], A[1001], B[501];

int main()
{
        ios_base::sync_with_stdio(false);
        int i, j, k;
        cin >> N >> M;
        for (i=1;i<=N;i++) cin >> W[i], B[i] = i;
        for (i=1;i<=M;i++) cin >> A[i];
        for (i=M;i;i--){
                int t = A[i];
                for (j=1;j<=N;j++) if (B[j] == t) break;
                for (k=j;--k;) B[k+1] = B[k];
                B[1] = t;
        }
        int ans = 0;
        for (i=1;i<=M;i++){
                int t = A[i];
                int sum = 0;
                for (j=1;j<=N;j++){
                        if (B[j] == t) break;
                        sum += W[B[j]];
                }
                ans += sum;
                for (k=j;--k;) B[k+1] = B[k];
                B[1] = t;
        }
        printf("%d\n", ans);
}