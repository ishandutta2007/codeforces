#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 50011, inf = 1000111222;

int n;
ll x[max_n], y[max_n], z[max_n];
bool used[max_n];

ll sqr(ll a) {
    return a * a;
}

ll dst(int i, int j) {
    return sqr(x[i] - x[j]) + sqr(y[i] - y[j]) + sqr(z[i] - z[j]);
}

map<int,vector<int>> mz;

vector<int> left_z;

bool cmp(int i, int j) {
    return y[i] < y[j];
}

void proc_xy(vector<int> v) {
    vector<int> left_x;
    map<int, vector<int>> mx;
    for (int i : v) {
        mx[x[i]].push_back(i);
    }
    for (auto p : mx) {
        vector<int> fxz = p.S;
        sort(fxz.begin(), fxz.end(), cmp);
        if (fxz.size() % 2 == 1) {
            left_x.push_back(fxz.back());
            fxz.pop_back();
        }
        for (int i = 0; i < fxz.size(); i += 2) {
            cout << fxz[i]  + 1 << ' ' << fxz[i + 1]  + 1 << "\n";
        }
    }
    if (left_x.size() % 2 == 1) {
        left_z.push_back(left_x.back());
        left_x.pop_back();
    }
    for (int i = 0; i < left_x.size(); i += 2) {
        cout << left_x[i]  + 1 << ' ' << left_x[i + 1]  + 1 << "\n";
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i <n; ++i) {
        cin >> x[i] >> y[i] >> z[i];
        mz[z[i]].push_back(i);
    }
    for (auto p : mz) {
        proc_xy(p.S);
    }
    if (left_z.size() % 2 == 1) {
        exit(228);
    }
    for (int i = 0; i < left_z.size(); i += 2) {
        cout << left_z[i] + 1 << ' ' << left_z[i + 1] + 1 << "\n";
    }
    return 0;
}