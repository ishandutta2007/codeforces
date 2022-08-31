#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100005;


int a = 0, b = 0, c = 0, n = 0;
int m[max_n] = {0};

int main()
{
    cin >> n >> a >> b;
    a--;
    b--;
    string s;
    cin >> s;
    if (s[a] == s[b])
    {
        cout << 0;
        return 0;
    }
    else
    {
        cout << 1;
        return 0;
    }
    return 0;
}