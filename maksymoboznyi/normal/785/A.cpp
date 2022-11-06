#include <bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
int n;
int main()
{
    string s;
    cin >> n;
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        if (s == "Tetrahedron")
            ans += 4;
        if (s == "Icosahedron")
            ans += 20;
        if (s == "Cube")
            ans += 6;
        if (s == "Dodecahedron")
            ans += 12;
        if (s == "Octahedron")
            ans += 8;
    }
    cout << ans;
    return 0;
}