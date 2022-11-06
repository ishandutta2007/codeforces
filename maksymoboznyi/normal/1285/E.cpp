#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

struct cell {
    int l, r;
};

bool cmp(cell a, cell b) {
    if (a.r != b.r)
        return a.r < b.r;
    return a.l > b.l;
}
int n, suff_mn[N], suff_ans[N];
cell a[N];

void add(vector<cell> &p, cell a) {
    int cur_l = a.l, cur_r = a.r;
    while (p.size() > 0 && p.back().r >= cur_l)
        if (p.back().l <= cur_l) {
            cur_l = p.back().l;
            p.pop_back();
            p.pb({cur_l, cur_r});
            return;
        } else {
            p.pop_back();
        }
    p.pb({cur_l, cur_r});
}

int stupid() {
    int res_max = 0;
    for (int i = 1; i <= n; i++) {
        suff_ans[n + 1] = 1;
        int l = 1e9 + 9;
        for (int j = n; j > 0; j--)
            if (j == i)
                suff_ans[j] = suff_ans[j + 1];
            else
                if (l == 1e9 + 9 || a[j].r >= l)
                    l = min(a[j].l, l), suff_ans[j] = suff_ans[j + 1];
                else
                    l = a[j].l, suff_ans[j] = suff_ans[j + 1] + 1;
        //cout << suff_ans[1] << endl;
        res_max = max(res_max, suff_ans[1]);
    }
    return res_max;

}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    srand(time(0));
    int oo;
    cin >> oo;
    int kk = 0;
    while (oo) {
        oo--;
        kk++;
        /*n = rand() % 5 + 2;
        cout << n << endl;
        for (int i = 1; i <= n; i++) {
            a[i].l = rand() % 6;
            a[i].r = rand() % 6;
            if (a[i].l > a[i].r)
                swap(a[i].l , a[i].r);
            cout << a[i].l << ' ' << a[i].r << endl;
        }*/
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i].l >> a[i].r;
        sort(a + 1, a + n + 1, cmp);
        /*for (int i = 1; i <= n; i++) {
            cout << a[i].l << ' ' << a[i].r << endl;
        }*/
        suff_mn[n] = a[n].l;
        for (int i = n - 1; i > 0; i--)
            suff_mn[i] = min(suff_mn[i + 1], a[i].l);
        int all = 1, r = a[n].r, l = a[n].l;
        suff_ans[n] = 1;
        for (int i = n - 1; i > 0; i--) {
            if (a[i].r >= l)
                l = min(l, a[i].l);
            else
                all++, l = a[i].l;
            suff_ans[i] = all;
        }
        //cout << '*' << suff_ans[3] << ' ' << suff_mn[3] << endl;
        vector<cell> p;
        int res = suff_ans[2];
        for (int i = 2; i < n; i++){
                add(p, a[i - 1]);
                if (suff_mn[i + 1] > a[i].l) {
                    int tmp = 0;
                    if (p[0].r >= suff_mn[i + 1])
                        tmp = suff_ans[i + 1];
                    else
                        if (p.back().r < suff_mn[i + 1])
                            tmp = suff_ans[i + 1] + p.size();//, cout << '2' << ' ' << tmp << endl;
                        else {
                            int l = 0, r = p.size();
                            while (l < r - 1) {
                                int m = (l + r) / 2;
                                if (p[m].r >= suff_mn[i + 1])
                                    r = m;
                                else
                                    l = m;
                            }
                            tmp = p.size() + suff_ans[i + 1] - (p.size() - r);
                            //cout << '3' << ' ' << tmp << endl;
                        }
                    res = max(res, tmp);
                    //cout << tmp << endl;
                } else {
                    res = max(res, suff_ans[1]);
                }
        }
        add(p, a[n - 1]);
        res = max(res, int(p.size()));

        cout << res << "\n";
        /*cout << stupid() << "\n";
        if (stupid() != res) {
            cout << "KEK";
            break;
        }*/
    }
    return 0;
}