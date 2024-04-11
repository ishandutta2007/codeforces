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
const int MAXN = (int)1e5 + 10;

int64 ACC[MAXN][2];
int64 L[MAXN];

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> L[i];
        ACC[i + 1][0] = ACC[i][0] + L[i];
    }
    sort(L, L + N);
    for (int i = 0; i < N; ++i)
        ACC[i + 1][1] = ACC[i][1] + L[i];

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int m,a,b;
        cin >> m >> a >> b;
        cout << ACC[b][m - 1] - ACC[a - 1][m - 1] << endl;
    }
}