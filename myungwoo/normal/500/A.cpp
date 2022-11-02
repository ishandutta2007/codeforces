#include <vector>
#include <map>
#include <set>
#include <queue>
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

#define MAXN 30005

int N, X;
int A[MAXN], V[MAXN];
queue <int> que;

int main()
{
        ios_base::sync_with_stdio(false);
        int i, j, k;
        scanf("%d%d", &N, &X);
        for (i=1;i<N;i++) scanf("%d", A+i);
        que.push(1); V[1] = 1;
        while (!que.empty()){
                int q = que.front(); que.pop();
                if (q == N) break;
                int t = q+A[q];
                if (V[t]) break;
                V[t] = 1; que.push(t);
        }
        puts(V[X]?"YES":"NO");
}