#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 400111, inf = 1000111222;

vector<pair<int, int>> a;
vector<pair<int, int>> b;
vector<int> comp;

int get_large(int small) {
    return comp[small];
}

int get_small(int large) {
    return lower_bound(comp.begin(), comp.end(), large) - comp.begin();
}
int n;

vector<int> st[max_n];
vector<int> fin[max_n];

bool have_in(const vector<pair<int, int>>& a, const vector<pair<int, int>>& b) {
    multiset<int> s, f;
    for (int i = 0; i < max_n; ++i) {
        st[i].clear();
        fin[i].clear();
    }
    for (int i = 0; i < n; ++i) {
        st[a[i].F].PB(i);
        fin[a[i].S].PB(i);
    }
    for (int i = 0; i < max_n; ++i) {
        for (int pos : st[i]) {
            s.insert(b[pos].F);
            f.insert(b[pos].S);
        }
        if (s.empty()) {
            continue;
        }
        if (*f.begin() < *s.rbegin()) {
            return true;
        }
        for (int pos : fin[i]) {
            s.erase(s.find(b[pos].F));
            f.erase(f.find(b[pos].S));
        }
    }
    return false;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int sa, fa, sb, fb;
        scanf("%d%d%d%d", &sa, &fa, &sb, &fb);
        a.emplace_back(sa, fa);
        b.emplace_back(sb, fb);
        comp.PB(sa);
        comp.PB(fa);
        comp.PB(sb);
        comp.PB(fb);
    }
    sort(comp.begin(), comp.end());
    comp.erase(unique(comp.begin(), comp.end()), comp.end());
    for (int i = 0; i < n; ++i) {
        a[i].F = get_small(a[i].F);
        a[i].S = get_small(a[i].S);


        b[i].F = get_small(b[i].F);
        b[i].S = get_small(b[i].S);
    }
    if (have_in(a, b) || have_in(b, a)) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    return 0;
}