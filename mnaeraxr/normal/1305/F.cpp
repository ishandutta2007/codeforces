#include <bits/stdc++.h>

#define endl '\n'

using namespace std;

long long gcd(long long a, long long b)
{
    while (b)
    {
        long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

void rr(vector<long long> &a)
{
    int n = a.size();
    for (int i = n - 1; i; --i)
    {
        int p = rand() % (i + 1);
        swap(a[i], a[p]);
    }
}

int total;
long long primes[50];

void pr(long long a)
{
    total = 0;
    if (a <= 1)
        return;
    while (a % 2 == 0)
        a /= 2;

    for (long long i = 3; i * i <= a; i += 2)
    {
        if (a % i == 0)
        {
            primes[total++] = i;
            a /= i;
            while (a % i == 0)
                a /= i;
        }
    }

    if (a > 1)
    {
        primes[total++] = a;
    }
}

bool ok()
{
    return 1. * clock() < 2.1 * CLOCKS_PER_SEC;
}

void fin(int answer)
{
    cout << answer << endl;
    exit(0);
}

int main()
{
    srand(time(0));

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    map<long long, int> checked;

    int answer = n;

    auto check = [&](long long p) {
        if (checked.find(p) != checked.end())
        {
            return checked[p];
        }

        int cur = 0;

        for (auto x : a)
        {
            if (x < p)
                cur += p - x;
            else
            {
                auto y = x % p;
                cur += min(y, p - y);
                if (cur >= answer)
                {
                    break;
                }
            }
        }

        return checked[p] = cur;
    };

    rr(a);

    answer = check(2);

    for (int i = 0; i < n && ok(); ++i)
    {
        for (int j = -1; j <= 1; ++j)
        {
            pr(a[i] + j);
            for (int k = 0; k < total; ++k)
            {
                answer = min(answer, check(primes[k]));
            }
        }
    }

    fin(answer);

    return 0;
}