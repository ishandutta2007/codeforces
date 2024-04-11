#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;

vector <int> anser;





int main()
    {
    FAST;


    cin >> n;

    data.resize(n);

    for (int i = 0; i < n; i++)
        {cin >> data[i]; k+= data[i];}

    k+= 2;
    k/= 2;

    m = data[0];

    anser.push_back(0);
    k-= data[0];

    for (int i = 1; i < n; i++)
        {
        if (data[i]*2 <= data[0])
            {
            anser.push_back(i);
            k-= data[i];
            }
        }


    if (k > 0)
        {
        cout << 0;
        return 0;
        }

    cout << anser.size() << endl;
    for (int i = 0; i < anser.size(); i++)
        {
        cout << anser[i]+1 << " ";
        }

    return 0;
    }