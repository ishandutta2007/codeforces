#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
        cerr << (*i) << " ";
    }
    cerr << "\n";
}

vector<vector<int> > ans;

void add(int a, int b, int c) {
    vector<int> vv = {a, b, c};
    ans.push_back(vv);
}

void add(int a, int b, int c, int d) {
    vector<int> vv = {a, b, c, d};
    ans.push_back(vv);
}

int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        while (n > 4) {
            int x = n;
            int y = n - 1;
            for (int i = 3; i < y; i += 2) {
                add(x, i, y, i + 1);
                add(x, i, y, i + 1);
            }
            add(x, y, 1);
            add(x, y, 2);
            add(x, 1, y, 2);
            n -= 2;
        }
        add(1, 2, 3);
        add(2, 3, 4);
        add(1, 3, 4);
        add(1, 2, 4);
    }
    else {
        while (n > 1) {
            int x = n;
            int y = n - 1;
            int z = n - 2;
            for (int i = 1; i < z; i += 2) {
                add(x, i, y, i + 1);
                add(x, i, y, i + 1);
            }
            add(x, y, z);
            add(x, y, z);
            n -= 2;
        }
    }
    printf("%d\n", (int)ans.size());
    for (int i = 0; i < ans.size(); ++i) {
        vector<int> vv = ans[i];
        printf("%d ", (int)vv.size());
        for (int j = 0; j < vv.size(); ++j)
            printf("%d ", vv[j]);
        printf("\n");
    }
    return 0;
}