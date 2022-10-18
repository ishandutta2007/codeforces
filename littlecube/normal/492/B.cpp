#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, l;
    double result = 0;
    vector<int> v;
    cin >> n >> l;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    result = max((double)v.front(), result);
    result = max((double)(l - v.back()), result);

    for (int i = 0; i < n - 1; i++)
    {
        result = max((double)(v[i+1] - v[i])/2.0, result);
    }
    cout << fixed << setprecision(10) << result << '\n';
}