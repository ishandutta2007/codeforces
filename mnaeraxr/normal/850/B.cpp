#include <bits/stdc++.h>

using namespace std;

// #define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

const int maxn = 2000001;

int p[maxn];
int64 freq[maxn];
int64 acc[maxn];
int64 vacc[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int64 x, y;
    cin >> n >> x >> y;

    int64 mop = x / y;

    for (int i = 0; i < n; ++i){
        int v; cin >> v;
        freq[v]++;
    }

    for (int i = 1; i < maxn; ++i){
        acc[i] = acc[i - 1] + freq[i];
        vacc[i] = vacc[i -  1] + acc[i];
    }

    int64 answer = 1LL * n * x;

    for (int i = 2; i < maxn; ++i){
        if (p[i]) continue;
        int64 cur = 0;

        for (int j = i; j < maxn && cur < answer; j += i){
            p[j] = 1;

            int64 pbeg = j - i, pend = j - 1;
            int64 pmid = max(pbeg, pend - mop);

            int64 val = 0;
            val += x * (acc[pmid] - acc[pbeg]);
            val += y * (vacc[pend] - vacc[pmid] - (pend - pmid) * acc[pmid]);
            cur += val;
        }

        answer = min(answer, cur);
    }

    cout << answer << endl;

    return 0;
}