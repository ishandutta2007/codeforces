#include <iostream>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ctime>
#include <unistd.h>

#define MP make_pair
#define PB push_back
#define F first
#define S second
#define prev azazan

using namespace std;

typedef long long ll;

const ll max_n = 100111, inf = 1000111222;

vector<ll> v[max_n];
vector<ll> ans[max_n];

vector<int> v2;

void dumb() {
    int a = 0;
    while (v2.size()) {
        ++a;
        int minn = max_n + 1;
        for (int i : v2) {
            minn = min(minn, i);
        }
        if (minn == v2.back()) {
            v2.pop_back();
        } else {
            v2.insert(v2.begin(), v2.back());
            v2.pop_back();
        }
    }
    cout << a << endl;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, a;
    cin >> n;
    int minn = max_n + 1;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        v2.push_back(a);
    }
    reverse(v2.begin(), v2.end());
    for (int i = 0; i < n; ++i) {
        //cin >> a;
        a = v2[i];
        //a = rand() % 100;
        //v2.PB(a);
        minn = min(minn, a);
        v[a].PB(i);
    }
    //dumb();
    for (int i = 0; i < max_n; ++i) {
        sort(v[i].begin(), v[i].end());
    }
    int cur = minn;
    ll v1 = 1, v2 = -1;
    ll pv1 = max_n + 1, pv2 = max_n + 1;
    for (int i = 0; i < max_n; ++i) {
        if (v[i].size() == 0) continue;
        for (int j = 0; j < v[i].size(); ++j) {
            ll anscur = 0;
            ll pcur = v[i][j];
            if (pv1 < pcur) {
                anscur = max(anscur, v1 + 1);
            }  else {
                anscur = max(anscur, v1);
            }
            if (v2 != -1) {
                if (pv2 < pcur) {
                    anscur = max(anscur, v2 + 1);
                }  else {
                    anscur = max(anscur, v2);
                }
            }
            ans[i].PB(anscur);
            //cout << anscur << ' ' ;
        }
        //cout << endl;
        v1 = -1, v2 = -1;
        pv1 = max_n + 5, pv2 = max_n + 5;
        for (int j = 0; j < v[i].size(); ++j) {
            if (ans[i][j] == v1) {
                pv1 = min(pv1, v[i][j]);
            } else if (ans[i][j] == v2) {
                pv2 = min(pv2, v[i][j]);
            } else {
                if (v1 == -1) {
                    v1 = ans[i][j];
                    pv1 = v[i][j];
                } else {
                    v2 = ans[i][j];
                    pv2 = v[i][j];
                }
            }
        }
    }
    ll ansall = 0;
    for (int i = 0; i < max_n; ++i) {
        for (int j = 0; j < v[i].size(); ++j) {
            ansall += ans[i][j];
        }
    }
    cout << ansall << endl;
    return 0;
}