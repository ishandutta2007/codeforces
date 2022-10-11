#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

struct kek {
    string s;
    int num;

    kek(string s = "", int num = 0) :
        s(s), num(num)
    {}
};

string get_rev(string s) {
    reverse(all(s));
    return s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        vector<string> dict(n);
        for (string& i : dict)
            cin >> i;
        map<string, int> mapa;
        for (string i : dict)
            mapa[i]++;
        vector<kek> oz, zo, oo, zz;
        for (int j = 0; j < n; j++) {
            string i = dict[j];
            if (i.size() == 1) {
                if (i[0] == '0')
                    zz.push_back({ i, j });
                else
                    oo.push_back({ i, j });
                continue;
            }
            if (i[0] == '1' && i.back() == '0')
                oz.push_back({ i, j });
            else if (i[0] == '0' && i.back() == '1')
                zo.push_back({ i, j });
            else if (i[0] == '0' && i.back() == '0')
                zz.push_back({ i, j });
            else
                oo.push_back({ i, j });
        }
        int ozS = oz.size(), zoS = zo.size(), ooS = oo.size(), zzS = zz.size();
        if (ooS != 0 && zzS != 0 && zoS + ozS == 0) {
            cout << "-1\n";
            continue;
        }
        vector<kek> cOz, cZo;
        int cntOz = 0, cntZo = 0;
        for (kek i : oz) {
            if (mapa[get_rev(i.s)])
                cntOz++;
            else
                cOz.push_back(i);
        }
        for (kek i : zo) {
            if (mapa[get_rev(i.s)])
                cntZo++;
            else
                cZo.push_back(i);
        }
        vector<int> ans;
        int fir = oz.size();
        int sec = zo.size();
        int need = abs(fir - sec) / 2;
        if (fir >= sec) {
            if (cOz.size() < need) {
                cout << "-1\n";
                continue;
            }
            for (int i = 0; i < need; i++)
                ans.push_back(cOz[i].num);
        } else {
            if (cZo.size() < need) {
                cout << "-1\n";
                continue;
            }
            for (int i = 0; i < need; i++)
                ans.push_back(cZo[i].num);
        }
        cout << ans.size() << '\n';
        for (auto i : ans)
            cout << i + 1 << ' ';
        cout << '\n';
    }
}