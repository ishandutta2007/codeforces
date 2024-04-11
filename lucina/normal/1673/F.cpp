#include<bits/stdc++.h>
using namespace std;

vector <int> grey_code(int b) {
    if (b == 1) {
        return {0, 1};
    }
    vector <int> foo = grey_code(b - 1);
    for (int i = foo.size() - 1 ; i >= 0 ; -- i) {
        foo.push_back(foo[i] | (1 << (b - 1)));
    }
    return foo;
}


vector <int> a, b, ex, ey;
int n, nq;

void prepare() {
    for (int j : grey_code(5)) {
        int xa = 0, xb = 0;
        for (int k = 0 ; k < 5 ; ++ k) {
            if (j >> k & 1) {
                xa += 1 << (k * 2);
                xb += 1 << (k * 2 + 1);
            }
        }
        a.push_back(xa);
        b.push_back(xb);
    }    
    for (int i = 0 ; i + 1 < a.size() ; ++ i) {
        ex.push_back(a[i + 1] ^ a[i]);
        ey.push_back(b[i + 1] ^ b[i]);
    }
    
}

pair <int, int> mp_to[2048];

int main() {
    
    cin.tie(0)->sync_with_stdio(false);
    prepare();
    cin >> n >> nq;

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 0 ; j < n - 1; ++ j) {
            cout << ex[j] << ' ';
        }
        cout << '\n';
    }

    for (int j = 0 ; j < n - 1 ; ++ j) {
        for (int i = 1 ; i <= n ; ++ i)
            cout << ey[j] << ' ';
        cout << '\n';
    }
    cout << flush;

    int sex = 0;
    ex.push_back(0); ey.push_back(0);
    for (int i = 0 ; i < n ; ++ i) {
        int sey = 0;
        for (int j = 0 ; j < n ; ++ j) {
            mp_to[sex ^ sey] = {i + 1, j + 1};
            sey ^= ey[j];
        }
        sex ^= ex[i];
    }

    int keep = 0;
    for (int i = 1 ; i <= nq ; ++ i) {
        int track;
        cin >> track;
        track ^= keep;
        cout << mp_to[track].second << ' ' << mp_to[track].first << endl;
        keep = track;
    }
}

    /***
     *
     *
     *
     * Let's see if you can reduce the sum by the fraction of 1/3
     * How to minimize 0 100 101 10000 10001 10100 10101
     * 1000000 1000100 10000101 1010000 1010001 1010100 1010101
     * well, grey code itself is a simple way to minimize sum
    */
    
    /**
        ok the sum is 47616
        very tight one :)
    */
    /**
    * begin real interaction
    */