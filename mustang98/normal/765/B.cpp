#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1000;

int main()
{
    string s;
    cin >> s;
    vector<int> v;
    for (int i = 0; i < s.size(); ++i)
    {
        v.pb(s[i] - 'a');
    }
    int last = -1;
    for (int i = 0; i < v.size(); ++i)
    {
        int cur = v[i];
        if (cur > last + 1)
        {
            cout << "NO";
            return 0;
        }
        if (cur == last + 1)
        {
            last++;
        }
    }
    cout << "YES";
    return 0;
}