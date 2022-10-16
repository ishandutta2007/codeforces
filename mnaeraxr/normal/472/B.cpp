/*
    Author: MarX
    School: UH
 */

#include <bits/stdc++.h>

using namespace std;

#define DB(x) cout<<#x<<"="<<x<<endl;
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 1<<30;
const double EPS = 1e-9;
const int MAXN = (int)2e3 + 10;

int L[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; ++i)
        cin >> L[i];

    sort(L, L + N);
    int ans = 0;
    for (int i = N - 1; i >= 0; i -= M)
    {
        ans += 2 * (L[i] - 1);
    }

    cout << ans << endl;

    return 0;
}