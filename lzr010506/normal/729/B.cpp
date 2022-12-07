#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector < vector < int > > matrix(n, vector < int >(m));
    vector < int > up(m, n);
    vector < int > down(m);
    vector < int > left(n, m);
    vector < int > right(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            {
                up[j] = min(up[j], i);
                down[j] = max(down[j], i);
                left[i] = min(left[i], j);
                right[i] = max(right[i], j);
            }
        }
    }
    int counter = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (matrix[i][j] == 0)
            {
                if (up[j] < i) ++counter;
                if (down[j] > i) ++counter;
                if (left[i] < j) ++counter;
                if (right[i] > j)  ++counter;
            }
        
    
    cout << counter << endl;
    return 0;
}