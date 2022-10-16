#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;

int L[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
    {
        cin >> L[i];
        L[i] += L[i - 1];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; ++i)
    {
        int v; cin >> v;
        int *p = lower_bound(L, L + N + 1, v);
        cout << p - L << endl;
    }

    return 0;
}