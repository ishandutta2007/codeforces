#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}


char s[1001000];
char t[1001000];

vector<int> vv;
int cc[100];

int main() {
    scanf("%s %s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '?')
            vv.push_back(i);
        else
            ++cc[s[i] - 'a'];
    }
    for (int i = 0; i < n; ++i) {
        int k = i % m;
        if (cc[t[k] - 'a']) {
            --cc[t[k] - 'a'];
        }
        else if (vv.size()) {
            s[vv.back()] = t[k];
            vv.pop_back();
        }
        else {
            break;
        }
    }
    printf("%s\n", s);
    return 0;
}