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

int N, A[333], P[333], B[333];
bool w[333][333], V[333];

int main()
{
        ios_base::sync_with_stdio(false);
        int i, j, k;
        scanf("%d", &N);
        for (i=1;i<=N;i++) scanf("%d", A+i), P[A[i]] = i;
        for (i=1;i<=N;i++) for (j=1;j<=N;j++) scanf("%1d", w[i]+j);
        for (i=1;i<=N;i++) w[i][i] = 1;
        for (k=1;k<=N;k++) for (i=1;i<=N;i++) for (j=1;j<=N;j++) w[i][j] |= w[i][k]&w[k][j];
        for (i=1;i<=N;i++){
                for (j=1;j<=N;j++) if (!V[j] && w[i][P[j]]){
                        V[j] = 1; break;
                }
                B[i] = j;
        }
        for (i=1;i<=N;i++) printf("%d ", B[i]); puts("");
}