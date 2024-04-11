#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const double eps = 1e-9;
const int oo = 0x3f3f3f3f;
const int mod = 1000000007;

int64 fak[30];

int64 comb(int n, int k) {
    if (k > n) return 0;
    return fak[n] / fak[k] / fak[n - k];
}

vector<int> op(int64 a) {
    vector<int> r;

    for (int i = 2; a; ++i){
        r.push_back(a % i);
        a /= i;
    }

    return r;
}

int64 brute(vector<int> r) {
    sort(r.begin(), r.end());

    int answer  = 0;
    set<int64> s;

    do {
        bool ok = true;
        for (int i = 0; i < r.size() && ok; ++i){
            if (r[i] >= i + 2) {
                ok = false;
            }
        }

        if (ok){
            answer++;
            int64 cur = 0;

            for (int i = (int)r.size() - 1; i >= 0; --i) {
                cur *= i + 2;
                cur += r[i];
            }

            auto rr = op(cur);
            sort(rr.begin(), rr.end());
            for (auto x : rr)
                cout << x << " ";
            cout << endl;
            s.insert(cur);
        }

    } while (next_permutation(r.begin(), r.end()));

    cout << answer << " " << s.size() << endl;

    return answer;
}

int64 count(vector<int> r) {
    int64 answer = 1;
    int n = r.size();

    for (int i = 0, j; i < n; i = j) {
        for (j = i; j < n && r[j] == r[i]; ++j);

        int v = r[i];
        int t = j - i;
        int vv = max(v, 1);

        answer *= comb(n - vv + 1 - i, t);
    }

    return answer;
}

void solve(int64 a) {
    auto r = op(a);

    sort(r.begin(), r.end());
    reverse(r.begin(), r.end());

    int64 answer = count(r);

    if (r.back() == 0) {
        r.pop_back();
        answer -= count(r);
    }

    cout << answer - 1 << endl;
    cout.flush();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    fak[0] = 1;
    for (int i = 1; i < 30; ++i)
        fak[i] = fak[i - 1] * i;

    int n; cin >> n;

    for (int i = 0; i < n; ++i){
        int64 a; cin >> a;
        solve(a);
    }

    return 0;
}