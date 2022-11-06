#include <bits/stdc++.h>

using namespace std;

const int N = 1000005, M = 1e6 + 7, P = 15426833;

struct HashMap {
    vector<pair<long long, int> > values[M];
    vector<int> used;
    bool count(long long w) {
        int m = ((long long)(w % M) * P + 3151) % M;
        for (int i = 0; i < values[m].size(); i++) {
            if (values[m][i].first == w) {
                return true;
            }
        }
        return false;
    }
    int& operator [] (long long w) {
        int m = ((long long)(w % M) * P + 3151) % M;
        for (int i = 0; i < values[m].size(); i++) {
            if (values[m][i].first == w) {
                return values[m][i].second;
            }
        }
        if (values[m].empty()) {
            used.push_back(m);
        }
        values[m].push_back({w, 0});
        return values[m].back().second;
    }
    void clear() {
        for (int i = 0; i < used.size(); i++) {
            values[used[i]].clear();
        }
        used.clear();
    }
};

long long getHash(long long x) {
    long long hash = 0;
    for (int i = 0; i < 18; i++) {
        hash *= 10;
        hash += x % 2;
        x /= 10;
    }
    return hash;
}

char type;
long long x;
int t;
HashMap mapa;

int main() {

    scanf("%d", &t);

    while (t--) {
        scanf(" %c", &type);
        scanf("%lld", &x);
        if (type == '+') {
            mapa[getHash(x)]++;
        } else if (type == '-') {
            mapa[getHash(x)]--;
        } else {
            printf("%d\n", mapa[getHash(x)]);
        }
    }

    return 0;
}