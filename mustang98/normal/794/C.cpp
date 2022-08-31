#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 300111, inf = 1000111222;

string so, si;
vector<char> vo, vi;
multiset<char> sei, seo;
char ans[max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
  //  cin >> n;
    cin >> so >> si;
    n = so.size();
    for (int i = 0; i < so.size(); ++i) {
        vo.PB(so[i]);
        vi.PB(si[i]);
    }
    int cnto = n / 2, cnti = n / 2;
    if (n % 2 == 1) cnto++;
    sort(vo.begin(), vo.end());
    sort(vi.begin(), vi.end());
    reverse(vo.begin(), vo.end());
    for (int i = 0; i < cnto; ++i) {
        seo.insert(vo.back());
        vo.pop_back();
    }
    for (int i = 0; i < cnti; ++i) {
        sei.insert(vi.back());
        vi.pop_back();
    }
 //   cout << cnto << ' ' << cnti << endl;
  //  cout << seo.size() << ' ' << sei.size() << endl;
    bool iso = 1;
    int fst = 0, lst = n - 1;
    for (int i = 0; i < n; ++i) {
        if (iso) {
            if (sei.size() == 0) {
                ans[fst++] = *seo.begin();
                break;
            }
            auto ito = seo.begin();

            auto iti = sei.end();
            iti--;
            if (*ito < *iti) {
                ans[fst++] = *ito;
                seo.erase(ito);
            } else {
                auto it1 = seo.end();
                it1--;
                ans[lst--] = *it1;
                seo.erase(it1);
            }
        } else {
            auto ito = seo.begin();

            auto iti = sei.end();
            iti--;
            if (*iti > *ito) {
                ans[fst++] = *iti;
                sei.erase(iti);
            } else {
                ans[lst--] = *sei.begin();
                sei.erase(sei.begin());
            }
        }
        iso = !iso;
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i];
    }
    return 0;
}