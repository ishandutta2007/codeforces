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
    //freopen("input.txt", "r", stdin);
    string so, sn, s1, s2;
    int n;
    cin >> s1 >> s2;
    cin >> n;
    while(n--)
    {
        cout << s1 << ' ' << s2 << "\n";
        cin >> so >> sn;
        if (s1 == so) s1 = sn;
        else s2 = sn;
    }
    cout << s1 << ' ' << s2 << "\n";
    return 0;
}