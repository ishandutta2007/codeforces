#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 100111, inf = 1000111222;

deque<int> dq;
int n, q;
vector<pair<int, int>> pr;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    int mx = -1;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        dq.push_back(a);
        if (a > mx) {
            mx = a;
        }
    }
    while(dq.front() != mx) {
        int a = dq.front();
        dq.pop_front();
        int b = dq.front();
        dq.pop_front();
        pr.push_back(MP(a, b));
        if (a > b) {
            dq.push_front(a);
            dq.push_back(b);
        } else {
            dq.push_front(b);
            dq.push_back(a);
        }
    }
    for (int i = 0; i < q; ++i) {
        ll ind;
        cin >> ind;
        --ind;
        if (ind < pr.size()) {
            printf("%d %d\n", pr[ind].F, pr[ind].S);
        } else {
            ind -= pr.size();
            ind %= (n - 1);
            printf("%d %d\n", dq.front(), dq[ind + 1]);
        }
    }

    return 0;
}