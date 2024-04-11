#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>
#include <string.h>
#include <stack>

using namespace std;

typedef long long int64;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DB(x) cout << #x << "=" << x
#define MP make_pair

const int MAXN = (int)1e5 + 10;
const int MOD = (int)1e9 + 7;

char S[1010][1010];
int V[1010];
int T[1010];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> S[i];

    int cnt = 0;
    for (int i = 0; i < m; ++i)
    {
        bool valid = true;
        for (int j = 1; j < n && valid; ++j)
        {
            if (V[j] != V[j - 1]) continue;
            if (S[j][i] < S[j - 1][i]) valid = false, cnt++;
        }
        if (!valid) continue;

        
        for (int j = 0, v = 0; j < n; ++v)
        {
            char cur = S[j][i];
            int vv = V[j];
            for (; j < n && S[j][i] == cur && V[j] == vv; ++j)
                T[j] = v;
        }
        for (int j = 0; j < n; ++j)
            V[j] = T[j];
    }
    cout << cnt << endl;

    return 0;
}