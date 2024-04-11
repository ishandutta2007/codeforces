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

pii L[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int a, b;
        cin >> a >> b;
        L[i] = MP(a, b);
    }
    sort(L, L + N);
    int l = 0;
    for (int i = 0; i < N; ++i)
    {
        if (L[i].second >= l)
            l = L[i].second;
        else
            l = L[i].first;
    }
    cout << l << endl;

    return 0;
}