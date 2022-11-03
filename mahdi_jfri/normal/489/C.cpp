#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<int> a, b;
int main()
{
    int n , m;
    cin >> m >> n;
    if(n > m * 9 || (n == 0 && m != 1))
    {
        cout << "-1 -1";
        return 0;
    }
    for(int i = 0; i < m; i++)
        a.push_back(0);
    for(int i = 0; i < m; i++)
        b.push_back(9);
    a[0] = 1;
    int x = 1;
    int i = a.size() - 1;
    while(x < n)
    {
        a[i] = (n - x > 9?9:n - x + a[i]);
        x = (n - x > 9? x + 9:n);
        i--;
    }
    if(x > n)
        a[0] = 0;
    for(int i = 0; i < m; i++)
        cout << a[i];
    cout << " ";
    x = m * 9;
    i = m - 1;
    while(x > n)
    {
        b[i] = (x - n >= 9? 0: 9 - (x - n));
        x = (x - n >= 9? x - 9: n);
        i--;
    }
    for(int i = 0; i < m; i++)
        cout << b[i];
}