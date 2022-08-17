#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111;

int check(int start, int cnt)
{
    for (int i = 0; i < cnt; ++i) {

    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, x;
    cin >> n >> x;
    n %= 6;
    string s[6];
    s[0] = "012";
    s[1] = "102";
    s[2] = "120";
    s[3] = "210";
    s[4] = "201";
    s[5] = "021";
    cout << s[n][x];
    return 0;
}