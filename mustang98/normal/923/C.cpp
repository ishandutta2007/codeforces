#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, maxp = 32, inf = 1000111222;

bool str[32];

int A[max_n];

struct node {
    int c[2];
    int cnt = 1;
    node () {
        c[0] = -1;
        c[1] = -1;
    }
};

vector<node> v;

node root;

void add() {
    int cur = 0;
    for (int i = 1; i < maxp; ++i) {
        //cout << i << endl;
        bool bit = str[i];
        if (v[cur].c[bit] == -1) {
            v[cur].c[bit] = v.size();
            v.PB(node());
        } else {
            v[v[cur].c[bit]].cnt++;
        }
        cur = v[cur].c[bit];
    }
}

void del() {
    int cur = 0;
    for (int i = 1; i < maxp; ++i) {
        bool bit = str[i];
        cur = v[cur].c[bit];
        v[cur].cnt--;
    }
    cur = 0;
    for (int i = 1; i < maxp; ++i) {
        bool bit = str[i];
        if (v[v[cur].c[bit]].cnt == 0) {
            v[cur].c[bit] = -1;
            break;
        }
        cur = v[cur].c[bit];
    }
}

ll findd() {
    bool res[32];
    res[0] = 0;
    int cur = 0;
    for (int i = 1; i < maxp; ++i) {
        bool bit = str[i];
        if (v[cur].c[bit] == -1) {
            res[i] = 1;
            cur = v[cur].c[!bit];
        } else {
            res[i] = 0;
            cur = v[cur].c[bit];
        }
    }
    ll ans = 0;
    for (int j = 31; j >= 0; --j) {
        if (res[31 - j]) {
            ans += (1 << j);
        }
    }
    return ans;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    root.cnt = inf;
    v.PB(root);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        //A[i] = rand();
        scanf("%d", A + i);
    }
    for (int i = 0; i < n; ++i) {
        int a;
        ll p;
        scanf("%d", &a);
        //p = rand();
        p = a;
        for (int j = 31; j >= 0; --j) {
            str[31 - j] = (p & (1LL << j)) > 0;
        }
        add();
    }

    for (int i = 0; i < n; ++i) {
        ll p = A[i];
        for (int j = 31; j >= 0; --j) {
            str[31 - j] = (p & (1LL << j)) > 0;
        }
        ll curp = findd();
        cout << (curp) << ' ';
        curp = curp ^ p;
        for (int j = 31; j >= 0; --j) {
            str[31 - j] = (curp & (1LL << j)) > 0;
        }
        del();
    }


    return 0;
}