#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 1, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    string s;
    int c = 0;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == 'a') {
            ++c;
        }
    }
    cout << min(int(s.size()), c * 2 - 1) << endl;

    return 0;
}