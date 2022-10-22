#include <iostream>
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

const int N = 200200;

void read(string & s) {
    char buffer[N];
    scanf("%s", &buffer);
    s = buffer;
}

bool solve() {

    int n, m;

    scanf("%d %d", &n, &m);

    string s;
    read(s);

    vec< int > a(26);
    for(int i = 0;i < 26;i++) a[i] = i;

    for(;m;m--) {
        char x, y, tx, ty;
        scanf(" %c %c", &x, &y);
        for(int i = 0;i < 26;i++) {
            if(a[i] == int(x - 'a')) tx = i;
            if(a[i] == int(y - 'a')) ty = i;
        }
        swap(a[tx], a[ty]);
    }

    for(int i = 0;i < n;i++) {
        char x = char(a[s[i] - 'a'] + 'a');
        printf("%c", x);
    }

    puts("");

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}