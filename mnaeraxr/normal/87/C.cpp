#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

int grundy[maxn];
int acc[maxn];
int answer[maxn];
int current[maxn];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int64 V; cin >> V;

    for (int64 i = 3; i <= V; ++i){
        int64 N = 2 * i;
        for (int64 n = 2; n * n <= N; ++n){
            if (N % n == 0){
                int64 k = N / n - n - 1;
                if (k >= 0 && k % 2 == 0){
                    k /= 2;
                    int64 cur = acc[k + n] ^ acc[k];
                    current[cur] = i;
                    if (cur == 0 && answer[i] == 0) answer[i] = n;
                }
            }
        }

        while (current[grundy[i]] == i) ++grundy[i];
        acc[i] = acc[i - 1] ^ grundy[i];
    }

    if (grundy[V] == 0) cout << -1 << endl;
    else cout << answer[V] << endl;

    return 0;
}