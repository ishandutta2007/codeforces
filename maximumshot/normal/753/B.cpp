#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

pii ask(string s) {
    cout << s << "\n";
    fflush(stdout);
    int x, y;
    cin >> x >> y;
    if(x == 4) {
        exit(0);
    }
    return make_pair(x, y);
}

int main() {

    vec< int > mas;

    for(int i = 0;i < 10;i++) {
        string t;
        t = "";
        for(int it = 0;it < 4;it++) {
            t.push_back( char(i + '0') );
        }
        pii tmp = ask(t);
        if(tmp.first == 1) {
            mas.push_back( i );
        }
    }

    assert((int)mas.size() == 4);

    do{
        string t = "";
        for(int x : mas) t.push_back(char(x + '0'));
        ask(t);
    }while(next_permutation(ALL(mas)));

    return 0;
}