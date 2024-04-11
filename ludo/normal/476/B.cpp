#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MAX 10

struct commands {
    int nleft, nright, unknown;

    commands() : nleft(0), nright(0), unknown(0) {}
};

typedef long long ll;
typedef pair<int, int> pii;

ll ck[MAX + 1][MAX + 1];

void init_ck()
{
    for (int i = 0; i <= MAX; i++) {
        ck[i][0] = ck[i][i] = 1;
    }
    for (int i = 2; i <= MAX; i++) {
        for (int j = 1; j < i; j++) {
            ck[i][j] = ck[i - 1][j] + ck[i - 1][j - 1];
        }
    }
}

void read_command(commands &c)
{
    string str;
    cin >> str;
    for (unsigned int i = 0; i < str.size(); i++) {
        if (str[i] == '-') {
            c.nright++;
        } else if (str[i] == '+') {
            c.nleft++;
        } else if (str[i] == '?') {
            c.unknown++;
        } else {
            cerr << "unknown character " << str[i] << endl;
        }
    }
}

int main()
{
    init_ck();

#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL

    commands c1, c2;
    read_command(c1);
    read_command(c2);

    cerr << c1.nleft << ", " << c1.nright << ", " << c1.unknown << endl;
    cerr << c2.nleft << ", " << c2.nright << ", " << c2.unknown << endl;

    double d;
    if (c2.nleft > c1.nleft || c2.nright > c2.nright) {
        d = 0.0;
    } else {
        c1.nleft -= c2.nleft;
        c1.nright -= c2.nright;
        d = ck[c1.nleft + c1.nright][c1.nleft];

        cerr << c1.nleft << ", " << c1.nright << ", " << c1.unknown << endl;
        cerr << c2.nleft << ", " << c2.nright << ", " << c2.unknown << endl;
        cerr << d << endl;

        for (int i = c1.nleft + c1.nright; i > 0; i--) {
            d *= 0.5;
        }
    }

    cout.precision(12);
    cout << fixed;
    cout << d << endl;

    return 0;
}