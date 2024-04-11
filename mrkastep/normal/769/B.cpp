#pragma warning (disable: 4996)
#include <iostream> 
#include <stdio.h> 
#include <cstdio> 
#include <algorithm> 
#include <vector> 
#include <map> 
#include <set> 
#include <string> 
#include <cstring> 
#include <valarray> 
#include <tuple> 
#include <complex> 
#include <bitset> 
#include <assert.h> 
#include <unordered_map>
#include <queue>

#define pb push_back 
#define mp make_pair 

typedef long long ll;

using namespace std;

int n;
pair<int, int> p[205];
queue<pair<int, int> > q;
vector<pair<int, int> > ans;

void solve() {
    int i, sum = 1, st[205];
    for (i = 0; i < 205; i++) {
        st[i] = 0;
    }
    for (i = 0; i < n; i++) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    q.push(p[0]);
    st[0] = 1;
    sort(p, p + n);
    while (sum != n && !q.empty()) {
        pair<int, int> t = q.front();
        q.pop();
        if (t.first > 0) {
            t.first--;
            if (t.first > 0) {
                q.push(t);
            }
            int maxi = 0;
            for (i = 0; i < n; i++) {
                if (st[p[i].second] == 0) {
                    maxi = max(maxi, p[i].first);
                }
            }
            for (i = 0; i < n; i++) {
                if (st[p[i].second] == 0 && p[i].first == maxi) {
                    q.push(p[i]);
                    st[p[i].second] = 1;
                    sum++;
                    ans.push_back(mp(t.second, p[i].second));
                    i = n;
                }
            }
        }
    }
    if (sum < n) {
        printf("-1");
        return;
    }
    printf("%d\n", ans.size());
    for (i = 0; i < ans.size(); i++) {
        printf("%d %d\n", ans[i].first + 1, ans[i].second + 1);
    }
}

int main() {
#ifdef _DEBUG 
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif 
    scanf("%d", &n);
    solve();
    return 0;
}