#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
#include <stack>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <chrono>
#include <string>
#include <assert.h>
#include <map>
#include <cstring>

using namespace std;

#define endl '\n'

void read(vector<long long> &X)
{
    for (auto &x : X)
        cin >> x;
    sort(X.begin(), X.end());
}

long long sqr(long long a)
{
    return a * a;
}

void test(long long a, long long b, long long c, long long &ans)
{
    long long cur = sqr(a - b) + sqr(b - c) + sqr(a - c);
    if (cur < ans)
        ans = cur;
}

long long go(vector<long long> &A, vector<long long> &B, vector<long long> &C)
{
    long long answer = 3000000000000000001LL;

    for (auto a : A)
    {
        int pb = lower_bound(B.begin(), B.end(), a) - B.begin();
        int pc = lower_bound(C.begin(), C.end(), a) - C.begin();

        for (int i = -1; i <= 1; ++i)
            for (int j = -1; j <= 1; ++j)
                if (0 <= pb + i && pb + i < B.size())
                    if (0 <= pc + j && pc + j < C.size())
                        test(a, B[pb + i], C[pc + j], answer);
    }

    return answer;
}

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<long long> A(a), B(b), C(c);
    read(A);
    read(B);
    read(C);

    long long answer = min({go(A, B, C),
                            go(B, C, A),
                            go(C, A, B)});

    cout << answer << endl;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }

    return 0;
}