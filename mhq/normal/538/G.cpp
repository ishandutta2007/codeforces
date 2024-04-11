#include <bits/stdc++.h>
using namespace std;
long long n, l;
const int maxN = 2 * (int)1e5 + 10;
long long t[maxN];
long long y[maxN];
long long x[maxN];
vector < pair < int, int > > f;
long long ceil(long long x, long long  y) {
    if (x >= 0) {
        return (x / y);
    }
    long long a = (x / y);
    if (a * y > x) a--;
    if ((a + 1) * y <= x) a++;
    return a;
}
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i];
        if (t[i] % 2 != (((x[i] + y[i]) % 2) + 2) % 2) {
            cout << "NO";
            return 0;
        }
        if (abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]) > t[i] - t[i - 1]) {
            cout << "NO";
            return 0;
        }
        f.push_back(make_pair(t[i] % l, i));
    }
    //cout << "HERE" << endl;
    f.push_back(make_pair(0, 0));
    long long l1 = -l;
    long long r1 = l;
    long long l2 = -l;
    long long r2 = l;
    sort(f.begin(), f.end());
    for (int i = 0; i + 1 < f.size(); i++) {
        long long t1 = f[i].first;
        long long t2 = f[i + 1].first;
        int ind1 = f[i].second;
        int ind2 = f[i + 1].second;
        if (t[ind1] < t[ind2]) {
            swap(ind1, ind2);
            swap(t1, t2);
        }
        if ((t[ind1] / l) == (t[ind2] / l)) continue;
        r1 = min(r1, ceil((x[ind1] + y[ind1] - x[ind2] - y[ind2] + abs(t1 - t2)), ((t[ind1] / l) - (t[ind2] / l))));
        l1 = max(l1, ceil((x[ind1] + y[ind1] - x[ind2] - y[ind2] - abs(t1 - t2) + (t[ind1] / l) - (t[ind2] / l) - 1), ((t[ind1] / l) - (t[ind2] / l))));
        r2 = min(r2, ceil((x[ind1] - y[ind1] - x[ind2] + y[ind2] + abs(t1 - t2)), ((t[ind1] / l) - (t[ind2] / l))));
        l2 = max(l2, ceil((x[ind1] - y[ind1] - x[ind2] + y[ind2] - abs(t1 - t2) + (t[ind1] / l) - (t[ind2] / l) - 1), ((t[ind1] / l) - (t[ind2] / l))));
    }
    int ind = f[f.size() - 1].second;
    r1 = min(r1, ceil((x[ind] + y[ind] + l - (t[ind] % l)), (1 + (t[ind] / l))));
    l1 = max(l1, ceil((x[ind] + y[ind] + (t[ind] % l) - l + (t[ind] / l)), (1 + (t[ind] / l))));
    r2 = min(r2, ceil((x[ind] - y[ind] + l - (t[ind] % l)), (1 + (t[ind] / l))));
    l2 = max(l2, ceil((x[ind] - y[ind] + (t[ind] % l) - l + (t[ind] / l)), (1 + (t[ind] / l))));
    if (abs(l1 - l) % 2 != 0) l1++;
    if (abs(l2 - l) % 2 != 0) l2++;
    if (abs(l2 - l1) % 2 != 0) {
        if (r2 > l2) l2++;
        else l1++;
    }
    if (r1 < l1 || r2 < l2) {
        cout << "NO";
        return 0;
    }
    int a = l1;
    int b = l2;
    int curr = 0;
    int curu = 0;
    f.push_back(make_pair(l, n + 1));
    x[n + 1] = (a + b) / 2;
    y[n + 1] = (a - b) / 2;
    t[n + 1] = 0;
    //cout << a << " " << b << endl;
    for (int i = 0; i + 1 < f.size(); i++) {
        int ind1 = f[i].second;
        int ind2 = f[i + 1].second;
        //cout << ind1 << " " << ind2 << '\n';
        long long c = (x[ind2] + y[ind2] - a * (t[ind2] / l) - x[ind1] - y[ind1] + a * (t[ind1] / l));
        long long d = (x[ind2] - y[ind2] - b * (t[ind2] / l) - x[ind1] + y[ind1] + b * (t[ind1] / l));
        long long e = f[i + 1].first - f[i].first;
        //cout << c << " " << d << endl;
        for (int i = 0; i < (c - d) / 2; i++) {
            curu++;
            cout << "U";
        }
        for (int i = 0; i < (d - c) / 2; i++) {
            curu--;
            cout << "D";
        }
        for (int i = 0; i < (c + d) / 2; i++) {
            curr++;
            cout <<"R";
        }
        for (int i = 0; i < (-c - d) / 2; i++) {
            curr--;
            cout << "L";
        }
        for (int i = 0; i < (e - max(abs(c), abs(d))); i += 2) {
            cout << "R";
            cout << "L";
        }
    }
    return 0;
}