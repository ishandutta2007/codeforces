#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

vector<int> t[256];
int nn;

void init() {
     for(int i = 0; i < 256; ++i)
             t[i].assign(nn, 0);
}

void add(int val, int p, char c) {
     for(int i = p; i < nn; i = (i | (i + 1)))
             t[c][i] += val;
}

int get(int l, char c) {
    int res = 0;
    for(int i = l; i >= 0; i = ((i & (i + 1)) - 1))
            res += t[c][i];
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    string s;
    cin >> s;
    string res = s;
    for(int i = 0; i < k - 1; ++i)
            res += s;
    s = res;
    nn = s.length();
    init();
    for(int i = 0; i < nn; ++i)
                    add(1, i, s[i]);
    set<int> e;
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
            int p;
            char c;
            cin >> p >> c;
            int l = 0, r = nn - 1;
            while(l < r) {
                    int m = (l + r) / 2;
                    if(get(m, c) >= p)
                              r = m;
                    else
                        l = m + 1;
            }
            add(-1, l, c);
            e.insert(l);
    }
    for(int i = 0; i < nn; ++i)
            if(!e.count(i))
                           cout << s[i];
    cin >> n;
    return 0;
}