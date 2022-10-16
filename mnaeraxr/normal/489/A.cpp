#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> V;
    for (int i = 0; i < n; ++i)
    {
        int v; cin >> v;
        V.push_back(v);
    }
    cout << n << endl;
    for (int i = 0; i < n; ++i)
    {
        int m = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (V[j] < V[m])
                m = j;
        }
        cout << i << " " << m << endl;
        V[m] = V[i];
    }
}