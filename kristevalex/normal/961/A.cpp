#include <bits/stdc++.h>
using namespace std;

int n, m, tmp;


vector<int> data;

int main()
    {
    cin >> n >> m;

    data.resize(n);

    for (size_t i = 0; i < m; i++)
        {
        cin >> tmp;
        data[tmp-1]++;
        }

    int sum = data[0];

    for (size_t i = 0; i < n; i++)
        {
        if (data[i] < sum) sum = data[i];
        }

    cout << sum;

    return 0;
    }