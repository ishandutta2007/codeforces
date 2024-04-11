#include <bits/stdc++.h>

using namespace std;

int main ()
    {
    size_t n, k;
    std::cin >> n >> k;

    vector<size_t> v(n);
    for (size_t i = 0; i < n; i++)
        std::cin >> v[i];

    sort(v.begin(), v.end());
    //for(auto&& x : v)
        //cout << x;


    if (k == 0)

        {
        if (v[0] > 1) cout << 1;
        else cout << -1;
        return 0;

        }

    if (n == k)
        {
        std::cout << v[k-1];
        return 0;
        }

    if (v[k-1] == v[k])
        {
        std::cout << -1;
        return 0;
        }


    std::cout << v[k-1];
    return 0;


    }