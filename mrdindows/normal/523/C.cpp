#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string a, b;
    cin >> a >> b;
    int i = 0, j = 0;
    int n = a.size();
    int m = b.size();
    for(j = 0; j < m; j++)
        if(i == n)
            break;
        else if(a[i] == b[j])
            i++;
    int A = j;
    i = 0, j = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for(j = 0; j < m; j++)
        if(i == n)
            break;
        else if(a[i] == b[j])
            i++;
    j = m - j;
    int B = j;
    cout << max(0, B - A + 1) << endl;
    return 0;
}