#include <iostream>
#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

const int MAXN = 100010;

typedef long long ll;

struct line {
    ll m, b;
    line (ll lm, ll lb) {
        m=lm; b=lb;
    }
    ll val(ll x) {
        return m*x+b;
    }
};

int n;
ll a[MAXN], b[MAXN], pre[MAXN], dp[MAXN];
deque<line> dq;

bool popback(line l1) {
    if (dq.size()<2) return 0;
    line l2=dq[dq.size()-1], l3=dq[dq.size()-2];
    return double(l1.b-l3.b)/(l3.m-l1.m)<=double(l2.b-l3.b)/(l3.m-l2.m);
    //return (l1.b-l3.b)*(l3.m-l2.m)<=(l2.b-l3.b)*(l3.m-l1.m);
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        pre[i+1]=pre[i]+a[i];
    }
    for (int i=0; i<n; i++) cin >> b[i];
    dq.push_back(line(b[0], -pre[1]*b[n-1]));
    for (int i=1; i<n; i++) {
        ll x=a[i];
        while (dq.size()>=2 && dq[1].val(x)<=dq[0].val(x)) dq.pop_front();
        dp[i]=dq.front().val(x)+pre[i]*b[n-1];
        line l=line(b[i], dp[i]-pre[i+1]*b[n-1]);
        while (popback(l)) dq.pop_back();
        dq.push_back(l);
    }
    cout << dp[n-1] << endl;
}