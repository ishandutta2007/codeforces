#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int d, sum, _min[31], _max[31], min_total = 0, max_total = 0;
    cin >> d >> sum;
    for (int i = 0; i < d; i++)
    {
        cin >> _min[i] >> _max[i];
        min_total += _min[i];
        max_total += _max[i];
    }
    if (min_total <= sum && sum <= max_total)
    {
        cout << "YES\n";
        sum -= min_total;
        for (int i = 0; i < d; i++)
        {
            if (sum > (_max[i] - _min[i]))
            {
                cout << _max[i];
                sum -= (_max[i] - _min[i]);
            }
            else if (sum != 0)
            {
                cout << _min[i] + sum;
                sum = 0;
            }else{
                cout << _min[i];
            }
             cout << " \n"[(i == d-1)];
        }
    }else{
        cout << "NO\n";
    }
}