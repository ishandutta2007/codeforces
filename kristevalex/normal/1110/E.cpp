#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data1, data2;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n;

    data1.resize(n);
    data2.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data1[i];

    for (int i = 0; i < n; i++)
        cin >> data2[i];

    if (data1[0] != data2[0])
        {
        cout << "NO";
        return 0;
        }

    if (data1[n-1] != data2[n-1])
        {
        cout << "NO";
        return 0;
        }


    for (int i = 0; i < n-1; i++)
        {
        data1[i]-= data1[i+1];
        data2[i]-= data2[i+1];
        }

    data1.pop_back();
    data2.pop_back();

    sort(data1.begin(), data1.end());
    sort(data2.begin(), data2.end());

    for (int i = 0; i < n-1; i++)
        {
        if (data1[i] != data2[i])
            {
            cout << "NO";
            return 0;
            }
        }



    cout << "YES";

    return 0;
    }