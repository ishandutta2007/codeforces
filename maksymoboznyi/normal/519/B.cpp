#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int N = 1e6;
ll n, a[N], b[N], c[N];
map<int, int> m, m2, m3;
int main()
{
    //ifstream cin("input.txt");
    //ofstream cout("output.txt");
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i], m[a[i]]++;
    for (int i = 0; i <n-1; i++)
    {
        cin >> b[i];
        m2[b[i]]++;
    }
    ll x;
    for (int i = 0; i < n; i++)
        if (m2[a[i]] < m[a[i]])
            x = a[i];
    cout << x<<endl;
    for (int i = 0; i < n -2; i++)
        cin >> b[i], m3[b[i]]++;
    for (int i = 0; i < n; i++)
        if (m3[a[i]] < m2[a[i]])
            x = a[i];
    cout << x;
    return 0;
}