#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N = 1e5;
int n;
string s[N];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int j = 0; j < n; j++)
    {
        bool r = false;
        for (int i = 0; i <j; i++)
            if (s[i] == s[j])
                r = true;
        if (r)
            cout << "YES\n";
            else
                cout << "NO\n";
    }
    return 0;
}