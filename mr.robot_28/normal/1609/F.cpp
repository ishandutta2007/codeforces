#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define ll long long
#define sz(a) (int)a.size()
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 7;
const int K = 1e7;
const int N = 1e6 + 1;
const int T = 350;

ll a[N];

int funct(ll p) {
    int ans = 0;
    while (p > 0) {
        ans += p & 1;
        p /= 2;
    }
    return ans;
}

ll sum = 0;
int values[N];
ll max_sub[N], min_sub[N];
vector <int> vec_min_left[100], vec_max_left[100], vec_min_right[100], vec_max_right[100];

int values_min[N], values_max[N];

void go_to(int l, int r) {
    if (l == r) {
        return;
    }
    int m = (r + l) / 2;
    go_to(l, m);
    go_to(m + 1,r);
    for (int i = l; i <= r; i++) {
        values_min[i] = values_max[i] = values[i];
    }
    min_sub[m] = max_sub[m] = a[m];
    for (int i = m - 1; i >= l; i--) {
        min_sub[i] = min(min_sub[i + 1], a[i]);
        max_sub[i] = max(max_sub[i + 1], a[i]);
        if (min_sub[i] == min_sub[i + 1]) {
            values_min[i] = values_min[i + 1];
        }
        if (max_sub[i] == max_sub[i + 1]) {
            values_max[i] = values_max[i + 1];
        }
    }
    min_sub[m + 1] = max_sub[m + 1] = a[m + 1];
    for (int i = m + 2; i <= r; i++) {
        min_sub[i] = min(a[i], min_sub[i - 1]);
        max_sub[i] = max(max_sub[i - 1], a[i]);
        if (min_sub[i] == min_sub[i - 1]) {
            values_min[i] = values_min[i - 1];
        }
        if (max_sub[i] == max_sub[i - 1]) {
            values_max[i] = values_max[i - 1];
        }
    }
    for (int i = 0; i <= 60; i++) {
        vec_min_left[i].clear();
        vec_min_right[i].clear();
        vec_max_left[i].clear();
        vec_max_right[i].clear();
    }
    for (int i = m; i >= l; i--) {
        vec_min_left[values_min[i]].push_back(i);
        vec_max_left[values_max[i]].push_back(i);
    }
    for (int i = m + 1; i <= r; i++) {
        vec_min_right[values_min[i]].push_back(i);
        vec_max_right[values_max[i]].push_back(i);
    }
    for (int i = 0; i <= 60; i++) {
        int r1 = -1;
        int l1 = 0;
        for (int j = 0; j < sz(vec_min_left[i]); j++) {
            while (r1 + 1 < sz(vec_max_right[i]) && min_sub[vec_max_right[i][r1 + 1]] >= min_sub[vec_min_left[i][j]]) {
                r1++;
            }
            while(l1 < sz(vec_max_right[i]) && max_sub[vec_max_right[i][l1]] <= max_sub[vec_min_left[i][j]]) {
                l1++;
            }
            if (l1 <= r1) {
                sum += r1 - l1 + 1;
            }
        }
        r1 = m;
        l1 = m;
        for (int j = 0; j < sz(vec_min_left[i]); j++) {
            while (l1 + 1 <= r && max_sub[l1 + 1] <= max_sub[vec_min_left[i][j]]) {
                l1++;
            }
            while (r1 + 1 <= r && min_sub[r1 + 1] >= min_sub[vec_min_left[i][j]]) {
                r1++;
            }
            if(values_min[vec_min_left[i][j]] == values_max[vec_min_left[i][j]]) {
                sum += min(l1, r1) - m;
            }
        }
        r1 = -1;
        l1 = 0;
        for (int j = 0; j < sz(vec_min_right[i]); j++) {
            while (r1 + 1 < sz(vec_max_left[i]) && min_sub[vec_max_left[i][r1 + 1]] > min_sub[vec_min_right[i][j]]) {
                r1++;
            }
            while(l1 < sz(vec_max_left[i]) && max_sub[vec_max_left[i][l1]] <= max_sub[vec_min_right[i][j]]) {
                l1++;
            }
            if (l1 <= r1) {
                sum += r1 - l1 + 1;
            }
        }
        r1 = m + 1;
        l1 = m + 1;
        for (int j = 0; j < sz(vec_min_right[i]); j++) {
            while (r1 - 1 >= l && min_sub[r1 - 1] > min_sub[vec_min_right[i][j]]) {
                r1--;
            }
            while(l1 - 1 >= l && max_sub[l1 - 1] <= max_sub[vec_min_right[i][j]]) {
                l1--;
            }
            if(values_min[vec_min_right[i][j]] == values_max[vec_min_right[i][j]]) {
                sum += m - max(l1, r1) + 1;
            }
        }
        if(i == 1) {
      //      cout << sum << "\n";
        }
    }
   // cout << l << " " << r << " ";
  //  cout << sum << "\n";
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        values[i] = funct(a[i]);
    }
    go_to(0, n - 1);
    cout << sum + n;    
    return 0;
}