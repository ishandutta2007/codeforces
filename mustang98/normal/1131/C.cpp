#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111, inf = 1000111222;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        v.PB(a);
    }
    sort(v.begin(), v.end());
    deque<int> d;
    for (int i = 0; i < v.size(); ++i) {
        if (i % 2 == 0) {
            d.push_front(v[i]);
        } else {
            d.push_back(v[i]);
        }
    }
    while(!d.empty()) {
        cout << d.front() << ' ';
        d.pop_front();
    }
    return 0;
}