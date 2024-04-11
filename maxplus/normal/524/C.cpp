#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main()
{
    long long n, k, q;
    map<long long, long long> a;
    vector<long long> b;
    cin >> n >> k;
    b.resize(n);
    a[0] = 0;
    for (int i = 0; i < n; i++)
    {
        long long nom;
        cin >> nom;
        b[i] = nom;
        for (long long j = 1; j <= k; j++)
        {
            if (a.find(nom * j) != a.end())
            {
                a[nom * j] = min(a[nom * j], j);
            }
            else
            {
                a[nom * j] = j;
            }
        }
    }
    cin >> q;
    for (int c = 0; c < q; c++)
    {
        long long sum;
        cin >> sum;
        long long curK = 100;
        for (int i = 0; i < n; i++)
        {
            for (long long j = 1; j <= k; j++)
            {
                if (a.find(sum - b[i] * j) != a.end())
                    curK = min(curK, j + a[sum - b[i] * j]);
            }
        }
        if (curK > k)
            cout << -1 << endl;
        else
            cout << curK << endl;
    }
    return 0;
}