#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
bool tk[Maxn];
vector <vector <int> > my[4];
vector <vector <int> > res;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) if (!tk[i]) {
        int v = i;
        vector <int> tmp;
        while (!tk[v]) {
            tk[v] = true;
            tmp.push_back(v);
            v = a[v];
        }
        while (tmp.size() >= 4) {
            vector <int> ans1;
            int tk = min(int(tmp.size()), 5);
            for (int i = tk; i > 0; i--)
                ans1.push_back(tmp[int(tmp.size()) - i]);
            res.push_back(ans1);
            vector <int> ans2;
            ans2.push_back(tmp.back());
            for (int i = tk; i > 1; i--)
                ans2.push_back(tmp[int(tmp.size()) - i]);
            res.push_back(ans2);
            for (int i = 0; i < tk; i++)
                tmp.pop_back();
            tmp.push_back(ans1[0]);
        }
        if (tmp.size() == 2) my[2].push_back(tmp);
        else if (tmp.size() == 3) my[3].push_back(tmp);
    }
    while (!my[2].empty() || !my[3].empty())
        if (!my[2].empty() && !my[3].empty()) {
            vector <int> fir = my[2].back(); my[2].pop_back();
            vector <int> sec = my[3].back(); my[3].pop_back();
            res.push_back({fir[0], fir[1], sec[0], sec[1], sec[2]});
            res.push_back({fir[1], fir[0], sec[2], sec[0], sec[1]});
        } else if (my[3].size() >= 2) {
            vector <int> fir = my[3].back(); my[3].pop_back();
            vector <int> sec = my[3].back(); my[3].pop_back();
            res.push_back({fir[0], fir[1], fir[2], sec[1], sec[2]});
            res.push_back({fir[2], fir[0], fir[1], sec[2], sec[1]});
            int num = sec[1];
            sec.pop_back(); sec.pop_back();
            sec.push_back(num);
            my[2].push_back(sec);
        } else if (my[2].size() >= 2) {
            vector <int> fir = my[2].back(); my[2].pop_back();
            vector <int> sec = my[2].back(); my[2].pop_back();
            res.push_back({fir[0], fir[1], sec[0], sec[1]});
            res.push_back({fir[1], fir[0], sec[1], sec[0]});
        } else if (!my[3].empty()) {
            vector <int> fir = my[3].back(); my[3].pop_back();
            res.push_back({fir[0], fir[1], fir[2]});
            res.push_back({fir[2], fir[0], fir[1]});
        } else if (!my[2].empty()) {
            vector <int> fir = my[2].back(); my[2].pop_back();
            res.push_back({fir[0], fir[1]});
            res.push_back({fir[1], fir[0]});
        }
    printf("%d\n", int(res.size()) / 2);
    for (int i = 0; i < res.size(); i += 2) {
        printf("%d\n", int(res[i].size()));
        for (int j = 0; j < res[i + 1].size(); j++)
            printf("%d%c", res[i + 1][j], j + 1 < res[i + 1].size()? ' ': '\n');
        for (int j = 0; j < res[i].size(); j++)
            printf("%d%c", res[i][j], j + 1 < res[i].size()? ' ': '\n');
    }
    return 0;
}