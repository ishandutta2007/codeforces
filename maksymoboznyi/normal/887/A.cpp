#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define ull unsigned long long
using namespace std;
const int N = 1e6;

int main()
{
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    int kol = 0, p1 =s.size()-1;
    bool r = 0;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '1')
        {
            p1 = i;
            break;
        }
    for (int i = int(s.size())-1; i > p1; i--)
        if (s[i] == '0')
            kol++;
    if (kol > 5)
        cout << "yes";
    else
        cout << "no";
    return 0;
}