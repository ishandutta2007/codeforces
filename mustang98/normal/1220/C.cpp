#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 500111, inf = 1000111222;

string s;
char buf[max_n];

string read_str() {
    scanf("%s", buf);
    return buf;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    s = read_str();
    char mn = 'z' + 5;
    for (int i = 0; i < s.size(); ++i) {
        if (mn < s[i]) {
            puts("Ann");
        } else {
            puts("Mike");
        }
        mn = min(mn, s[i]);
    }

    return 0;
}