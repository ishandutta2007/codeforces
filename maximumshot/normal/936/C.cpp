#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

void move(string& s, int len) {
    string t = "";
    while(len--) {
        t.push_back(s.back());
        s.pop_back();
    }
    s = t + s;
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;
    string s, t;

    cin >> n >> s >> t;

    {
        string s2 = s;
        string t2 = t;
        sort(ALL(s2));
        sort(ALL(t2));
        if(s2 != t2) {
            cout << "-1\n";
            return 0;
        }
    }

    vec< int > res;

    if(n % 2) {
        int i = n / 2;
        int d = 1;
        for(int l = 0;l < n;l++) {

            char c = t[i];

            int j = l;
            while(s[j] != c) j++;

            int beta = n - j - 1;
            int alphax = j - l + 1;
            int per = l;

            res.push_back(beta);
            move(s, beta);
            res.push_back(alphax);
            move(s, alphax);
            res.push_back(per);
            move(s, per);

            i += d;
            d = d > 0 ? -d - 1 : -d + 1;
        }
        res.push_back(n);
        move(s, n);
    }else {
        int i = n / 2 - 1;
        int d = 1;
        for(int l = 0;l < n;l++) {

            char c = t[i];

            int j = l;
            while(s[j] != c) j++;

            int beta = n - j - 1;
            int alphax = j - l + 1;
            int per = l;

            res.push_back(beta);
            move(s, beta);
            res.push_back(alphax);
            move(s, alphax);
            res.push_back(per);
            move(s, per);

            i += d;
            d = d > 0 ? -d - 1 : -d + 1;
        }
    }

    assert(s == t);

//    cout << s << " " << t << "\n";

    printf("%d\n", (int)res.size());

    for(int x : res) {
        printf("%d ", x);
    }

    puts("");

    return 0;
}