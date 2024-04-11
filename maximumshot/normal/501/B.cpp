#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>

#include <conio.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

void read(string & s) {
    char buffer[22];
    scanf("%s", &buffer);
    s = buffer;
}

bool solve() {
    
    map< string, string > a;
    // {now, old}

    int q;
    scanf("%d", &q);

    string x, y, s;

    for(;q;q--) {
        read(x);
        read(y);

        if(a.count(x)) {
            s = a[x];
            a.erase(x);
            a[y] = s;
        }else {
            a[y] = x;
        }
    }

    cout << (int)a.size() << '\n';

    for(auto i : a) {
        cout << i.second << " " << i.first << '\n';
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}