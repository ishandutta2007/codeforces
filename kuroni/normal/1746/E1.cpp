#include <bits/stdc++.h>
using namespace std;

int ask(int msk, vector<vector<int>>& divisions) {
    vector<int> tmp;
    for (int i = 0; i < divisions.size(); i++) {
        if (msk >> i & 1) {
            for (int v : divisions[i]) {
                tmp.push_back(v);
            }
        }
    }
    cout << "? ";
    cout << tmp.size() << " ";
    for (int v : tmp) {
        cout << v << " ";
    }
    cout << endl;
    string res; cin >> res; return (res == "YES");
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int div = 4, nxt = 2;
    vector<int> strategy = {3, 5, 5, 3};
    vector<int> resp(1 << div);
    // generating response
    {
        for (int msk = 0; msk < (1 << div); msk++) {
            int tot = 0;
            for (int ans = 0; ans < div; ans++) {
                int res = 0;
                for (int i = 0; i < strategy.size(); i++) {
                    int xd = (msk >> i & 1) ^ (strategy[i] >> ans & 1) ^ 1;
                    res ^= (xd << i);
                }
                bool check = true;
                for (int i = 0; i < (int)strategy.size() - 1; i++) {
                    if (!(res >> i & 1) && !(res >> (i + 1) & 1)) {
                        check = false;
                    }
                }
                if (check) {
                    resp[msk] ^= (1 << ans);
                }
            }
            assert(__builtin_popcount(resp[msk]) <= nxt);
        }
    }
    int n; cin >> n;
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
    }
    while (vec.size() >= 3) {
        vector<vector<int>> xd(div);
        for (int i = 0; i < div; i++) {
            int sz = vec.size() / (div - i);
            while (xd[i].size() < sz) {
                xd[i].push_back(vec.back());
                vec.pop_back();
            }
        }
        int res = 0;
        for (int i = 0; i < strategy.size(); i++) {
            res ^= (ask(strategy[i], xd) << i);
        }
        for (int i = 0; i < div; i++) {
            if (resp[res] >> i & 1) {
                for (int v : xd[i]) {
                    vec.push_back(v);
                }
            }
        }
    }
    {
        string res;
        cout << "! " << vec[0] << endl; cin >> res;
        if (res == ":(") {
            cout << "! " << vec[1] << endl; cin >>res;
            assert(res == ":)");
        }
    }
}