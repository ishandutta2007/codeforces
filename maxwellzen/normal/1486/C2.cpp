#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pi pair<int, int>
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define F first
#define S second
int n, mid, l, r, ans, m, c;
map<pi, int> queries;

int ask(int l, int r) {
    if (queries.find(mp(l, r))!=queries.end()) return queries[mp(l, r)];
    if (c==40) return l;
    cout << "? " << l << ' ' << r << endl;
    int temp;
    cin >> temp;
    c++;
    queries[mp(l, r)]=temp;
    return temp;
}

int main() {
    cin >> n;
    mid = ask(1, n);
    if (mid != 1 && ask(1, mid)==mid) {
        l=2; r=mid-1; ans=1;
        while (l <= r) {
            m = (l+r)/2;
            if (ask(m, mid)==mid) {
                ans=m;
                l = m+1;
            } else r=m-1;
        }
    } else {
        l = mid+1; r = n-1; ans = n;
        while (l <= r) {
            m = (l+r)/2;
            if (ask(mid, m)==mid) {
                ans = m;
                r = m-1;
            } else l = m+1;
        }
    }
    cout << "! " << ans << endl;
    return 0;
}