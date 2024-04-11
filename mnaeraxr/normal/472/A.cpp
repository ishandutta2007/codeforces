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

bool iscomposite(int n)
{
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
            return true;
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = 2; i <= N; ++i)
    {
        if (iscomposite(i) && iscomposite(N - i))
        {
            cout << i << " " << N - i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}