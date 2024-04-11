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

int main() {
    vector<int> v;
    int s;
    for (int i =0; i < 11; ++i) {
        int a;
        cin >> a;
        v.push_back(a);
    }

/*
per nextum in unam tum XI conscribementis {
    vestibulo perlegementum da varo.
    morde varo.
    seqis cumula varum.
}*/

reverse(v.begin(), v.end());
for (double a : v) {
    double ares = sqrt(abs(a));
    double bres = pow(a, 3) * 5;
    double res = ares + bres;
    //aresultum tum bresultum addementum da resulto.

    if (res < 400) {
        printf("f(%d) = %.2f\n", int(a), res);
    } else {
        printf("f(%d) = MAGNA NIMIS!\n", int(a));
    }
}

    return 0;
}