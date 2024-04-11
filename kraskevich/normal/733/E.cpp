#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<ll> sumU;
vector<ll> U;
vector<ll> sumD;
vector<ll> D;

ll get_sum_d(int l, int r) {
    ll res = sumD[r];
    if (l != 0)
        res -= sumD[l - 1];
    return res;
}

ll get_sum_u(int l, int r) {
    ll res = sumU[r];
    if (l != 0)
        res -= sumU[l - 1];
    return res;
}
        
int main() {
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
        if (s[i] == 'D') {
            D.push_back(i);
            ll old = 0;
            if (sumD.size())
                old = sumD.back();
            sumD.push_back(old + i);
        } else {
            U.push_back(i);
            ll old = 0;
            if (sumU.size())
                old = sumU.back();
            sumU.push_back(old + i);
        }
    int pu = -1;
    int pd = 0;
    for (int i = 0; i < n; i++) {
        if (pd < D.size() && D[pd] == i)
            pd++;
        int su = pu + 1;
        int sd = int(D.size()) - pd;
        // cerr << su << " " << sd << endl;
        if (s[i] == 'U') {
            ll res = -i;
            int kd = min(sd, su + 1);
            int ku = min(su, sd);
            if (kd != 0)
                res += 2 * get_sum_d(pd, pd + kd - 1);
            if (ku != 0) 
                res -= 2 * get_sum_u(pu - ku + 1, pu);
            if (sd <= su)
                res += n;
            else
                res++;
            cout << res << " ";
        } else {
            ll res = i;
            int ku = min(su, sd + 1);
            int kd = min(su, sd);
            if (kd != 0)
                res += 2 * get_sum_d(pd, pd + kd - 1);
            if (ku != 0) 
                res -= 2 * get_sum_u(pu - ku + 1, pu);
            if (su <= sd)
                res++;
            else
                res += n;
            cout << res << " ";
        }
        if (pu + 1 < U.size() && U[pu + 1] == i)
            pu++;
    }
    cout << endl;
    return 0;
}