#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

vector<long long> data;

long long a, b, k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    //cin >> n;

    string a, b;
    cin >> a >> b;

    if (a.size() != b.size())
        {
        cout << "NO";
        return false;
        }

    for (int i = 0; i < a.size(); i++)
        {
        if (a[i] == 'a' || a[i] == 'e' || a[i] == 'i' || a[i] == 'o' || a[i] == 'u') a[i] = '0';
        else a[i] = '1';
        }

for (int i = 0; i < b.size(); i++)
        {
        if (b[i] == 'a' || b[i] == 'e' || b[i] == 'i' || b[i] == 'o' || b[i] == 'u') b[i] = '0';
        else b[i] = '1';
        }




    cout << ((a==b)? "YES":"NO");

    return 0;
    }