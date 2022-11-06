#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 1e6 + 6;

struct word {
    int kol, last, num;
    string s;
};

struct good {
    pair<int, int> a;
    pair<int, int> b;
};

bool cmp(word a, word b) {
    if (a.kol != b.kol)
        return a.kol < b.kol;
    return a.last < b.last;
}

int n, used[N];
word a[N];
vector<good> ans;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].s;
        for (int j = 0; j < a[i].s.size(); j++)
            if (a[i].s[j] == 'a' || a[i].s[j] == 'o' || a[i].s[j] == 'i' || a[i].s[j] == 'u' || a[i].s[j] == 'e')
                a[i].kol++, a[i].last = a[i].s[j];
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        a[i].num = i;
    for (int i = 2; i <= n; i++)
        if (a[i].kol == a[i - 1].kol && a[i].last == a[i - 1].last && !used[i - 1]){
            used[i] = used[i - 1] = 1;
            ans.pb({{i - 1, i}, {-1, -1}});
        }
    vector<word> b;
    for (int i = 1; i <= n; i++) {
        if (!used[i])
            b.pb(a[i]);
        used[i] = 0;
    }
    int cur = 0;
    for (int i = 1; i < b.size(); i++)
        if (b[i].kol == b[i - 1].kol && cur < ans.size() && !used[i - 1])
            ans[cur] = {ans[cur].a,make_pair(b[i].num, b[i - 1].num)}, used[i] = used[i - 1] = 1, cur++;
    int last = ans.size() - 1;
    while (last > cur)
    {
        ans[cur] = {ans[cur].a, ans[last].a};
        ans.pop_back();
        cur++;
        last--;
    }
    //cout << last << ' ' << cur << endl;
    if (last == cur)
        ans.pop_back();
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << a[ans[i].b.first].s << ' ' << a[ans[i].a.first].s << "\n" << a[ans[i].b.second].s << ' ' << a[ans[i].a.second].s << "\n";
    return 0;
}