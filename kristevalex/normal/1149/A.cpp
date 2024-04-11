#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> n;

    //data.resize(n);

    for (int i = 0; i < n; i++)
        {
        cin >> tmp;

        if (tmp == 1) a++;
        else b++;
        }

    if (b > 0)
        {
        cout << "2 ";
        --b;
        }

    for (int i = 1; i < 2*((a+1)/2); i++)
        {
        cout << "1 ";
        }

    for (int i = 0; i < b; i++)
        {
        cout << "2 ";
        }



    if (a%2 == 0 && a != 0) cout << "1 ";

    return 0;
    }