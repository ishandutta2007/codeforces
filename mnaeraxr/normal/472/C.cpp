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

string L[MAXN][2];
int P[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> L[i][0] >> L[i][1];

        if (L[i][1] < L[i][0])
            swap(L[i][0], L[i][1]);
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> P[i];
        P[i]--;
    }

    bool valid = true;
    for (int i = 1; i < N; ++i)
    {
        int p = P[i];
        if (L[p][0] > L[P[i - 1]][0])
            continue;
        else if (L[p][1] > L[P[i - 1]][0])
            swap(L[p][0],L[p][1]);
        else
        {
            valid = false;
            break;
        }
    }
    if (valid)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}