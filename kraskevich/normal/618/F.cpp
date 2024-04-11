#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

struct Item {
    int delta;
    pii pos;
    
    Item(int delta = 0, pii pos = pii()): delta(delta), pos(pos) {}
    
    bool operator<(const Item& rhs) const {
        if (delta != rhs.delta)
            return delta < rhs.delta;
        return pos < rhs.pos;
    }
};

void print(const vector<int>& v) {
    cout << v.size() << endl;
    for (int x : v)
        cout << x << " ";
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    vector<ll> p_a(1);
    vector<ll> p_b(1);
    for (int i = 0; i < n; i++) {
        ll old_a = p_a.back();
        p_a.push_back(old_a + a[i]);
        ll old_b = p_b.back();
        p_b.push_back(old_b + b[i]);
    }
    bool swapped = false;
    if (p_a.back() > p_b.back()) {
        swap(p_a, p_b);
        swapped = true;
    }
    vector<Item> items(1);
    for (int i = 1; i < p_a.size(); i++) {
        int j = upper_bound(p_b.begin(), p_b.end(), p_a[i]) - p_b.begin() - 1;
        items.push_back(Item(p_a[i] - p_b[j], pii(i, j)));
    }
    sort(items.begin(), items.end());
    for (int i = 0; i < n; i++)
        if (items[i].delta == items[i + 1].delta) {
            vector<int> i_a;
            vector<int> i_b;
            for (int j = items[i].pos.first + 1; j <= items[i + 1].pos.first; j++)
                i_a.push_back(j);
            for (int j = items[i].pos.second + 1; j <= items[i + 1].pos.second; j++)
                i_b.push_back(j);
            if (swapped)
                swap(i_a, i_b);
            print(i_a);
            print(i_b);
            return 0;
        }
    assert (false);
}