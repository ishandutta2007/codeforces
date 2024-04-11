#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define PI 3.14159265358979323846

ll gcd(ll a, ll b){
    a = abs(a);
    b = abs(b);
    if (a == 0) return b;
    else if (b == 0) return a;
    ll newa = b % a;
    ll newb = a;
    ll placeholder;
    while (newa != 0) {
        placeholder = newa;
        newa = newb % newa;
        newb = placeholder;
    }
    return newb;
}

//ll dot(ll x1, ll y1, ll x2, ll y2) {
//    return x1*x2 + y1*y2;
//}
//
//bool right(ll x1, ll y1, ll x2, ll y2) {
//    ll g1 = gcd(x1, y1), g2 = gcd(x2, y2);
//    x1 /= g1; y1 /= g1; x2 /= g2; y2 /= g2;
//    return x1*y1 == -1*x2*y2;
//}
//
//double mag(ll x, ll y) {
//    return sqrt((double)(pow(x, 2)+pow(y, 2)));
//}
//
//double angle(ll x1, ll y1, ll x2, ll y2) {
//    return acos((double)dot(x1, y1, x2, y2) / (mag(x1, y1)*mag(x2, y2)));
//}

bool obtuse(ll x1, ll y1, ll x2, ll y2) {
    ll g1 = gcd(x1, y1), g2 = gcd(x2, y2);
    x1 /= g1; y1 /= g1; x2 /= g2; y2 /= g2;
    return x1*x2 <= -1*y1*y2;
}

int main() {
    ll n;
    cin >> n;
    vector<ll> x(n), y(n), perm(n);
    for (ll i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
        perm[i] = i+1;
    }
    for (int i = 0; i < n; i++) {
        bool works = true;
        for (ll i = 0; i < n-2; i++) {
            if (obtuse(x[i]-x[i+1], y[i]-y[i+1], x[i+2]-x[i+1], y[i+2]-y[i+1])) {
                works = false;
                swap(perm[i+1], perm[i+2]);
                swap(x[i+1], x[i+2]);
                swap(y[i+1], y[i+2]);
            }
        }
        if (works) break;
    }
    for (ll i : perm) cout << i << " ";
    cout << endl;
}