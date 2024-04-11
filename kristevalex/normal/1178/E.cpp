#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(false); \
             cin.tie(nullptr);                 \
             cout.tie(nullptr)

string data;

long long k, n, m, tmp, ans = 0;





int main()
    {
    FAST;


    cin >> data;

    vector<char> ans;
    n = data.size();
    m = n/4;

    for (int i = 0; i < 2*m; i+= 2)
        {
        int a = 0, b = 0, c = 0;

        if (data[i] == 'a') ++a;
        if (data[i] == 'b') ++b;
        if (data[i] == 'c') ++c;

        if (data[i+1] == 'a') ++a;
        if (data[i+1] == 'b') ++b;
        if (data[i+1] == 'c') ++c;

        if (data[n-i-1] == 'a') ++a;
        if (data[n-i-1] == 'b') ++b;
        if (data[n-i-1] == 'c') ++c;

        if (data[n-i-2] == 'a') ++a;
        if (data[n-i-2] == 'b') ++b;
        if (data[n-i-2] == 'c') ++c;

        if (a == 2) ans.push_back('a');
        else if (b == 2) ans.push_back('b');
        else if (c == 2) ans.push_back('c');
        }






    for (int i = 0; i < ans.size(); i++)
        {
        cout << ans[i];
        }

    if (n%4 != 0)
        {
        cout << data[2*m];
        }


    for (int i = ans.size()-1; i >= 0; --i)
        {
        cout << ans[i];
        }

    cout << endl;

    return 0;
    }