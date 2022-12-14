#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;


int get_(int param)
    {
    int low = -1;
    int high = n;
    while (high - low > 1)
        {
        int middle = (low + high)/2;
        if (data[middle] <= param)
            low = middle;
        else
            high = middle;
        }

    return low+1;
    }

long long query (int left, int right)
    {
    long long quantity = get_(right) - get_(left-1);

    if (quantity == 0) return a;

    long long as = (b)*((long long)(right - left + 1))*quantity;
    if (left == right) return as;

    int middle = (left+right)/2;
    as = min(as, (query(left, middle) + query(middle+1, right)));

    return as;
    }


int main()
    {
    FAST;


    int n_2[40] = {};
    n_2[0] = 1;
    for (int i = 1; i < 32; i++)
        {
        n_2[i] = 2*n_2[i-1];
        }


    cin >> m >> n >> a >> b;

    data.resize(n);

    for (int i = 0; i < n; i++)
        cin >> data[i];

    sort(data.begin(), data.end());





    cout << query(1, n_2[m]);

    return 0;
    }