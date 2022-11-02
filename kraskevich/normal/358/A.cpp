#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    bool ok = true;
    for (int s1 = 0; s1 < n; s1++)
        for (int s2 = s1 + 2; s2 < n - 1; s2++)
        {
            int e1 = s1 + 1;
            int e2 = s2 + 1;
            int a = x[s1];
            int b = x[e1];
            int c = x[s2];
            int d = x[e2];
            if (a > b)
                swap(a, b);
            if (c > d)
                swap(c, d);
            if (min(b, d) >= max(a, c) && min(b, d) - max(a, c) != min(b - a, d - c))
                ok = false;
        }
    if (ok)
        cout << "no";
    else
        cout << "yes";


    return 0;
}