#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const int max_n = 100111, inf = 1000111222;

int n, m;
vector<int> v[max_n];
bool sh[max_n];
bool frozen[max_n];

vector<int> sl[max_n]; //    ,   
vector<pair<int, int> > req; //  ,  -  

bool vis[max_n];

void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = 1;
    if (frozen[cur] && sh[cur] == 0) {
        cout << "No" << endl;
        exit(0);
    }
    frozen[cur] = 1;
    sh[cur] = 1;
    for (int i = 0; i < sl[cur].size(); ++i) {
        dfs(sl[cur][i]);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int l, a;
        cin >> l;
        for (int j = 0; j < l; ++j) {
            cin >> a;
            --a;
            v[i].PB(a);
        }
    }
    for (int i = 0; i < n - 1; ++i) {
        vector<int>& a = v[i];
        vector<int>& b = v[i + 1];
        for (int j = 0; j < min(a.size(), b.size()); ++j) {
            if (a[j] != b[j]) {
                if (a[j] < b[j]) {
                    //sl.PB(MP(b[j], a[j]));
                    sl[b[j]].PB(a[j]);
                    break;
                } else {
                    req.PB(MP(a[j], b[j]));
                    break;
                }
            } else {
                if (j == b.size() - 1 && a.size() > b.size()) {
                    cout << "No" << endl;
                    exit(0);
                }
            }
        }
    }
    for (int i = 0; i < req.size(); ++i) {
        int so_sh = req[i].F;
        int bez_sh = req[i].S;
        if (!frozen[so_sh]) {
            sh[so_sh] = 1;
            frozen[so_sh] = 1;
        } else {
            if (sh[so_sh] == 0) {
                cout << "No" << endl;
                exit(0);
            }
        }

        if (!frozen[bez_sh]) {
            sh[bez_sh] = 0;
            frozen[bez_sh] = 1;
        } else {
            if (sh[bez_sh] == 1) {
                cout << "No" << endl;
                exit(0);
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        if (sh[i] == 1 && frozen[i]) {
            dfs(i);
        }
    }
    cout << "Yes" << endl;
    vector<int> ans;
    for (int i = 0; i < m; ++i) {
        if (sh[i]) {
            ans.PB(i);
        }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] + 1 << ' ';
    }
    return 0;
}