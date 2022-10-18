#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

struct enevlop
{
    int w, h, val, id, back;
    enevlop(int w, int h, int id) : w(w), h(h), val(1), id(id), back(0){};
};

int n, W, H, maxindex = 0;
vector<enevlop> v;
map<int, int> m;

int main()
{
    cin >> n >> W >> H;
    for (int i = 1; i <= n; i++)
    {
        int w, h;
        cin >> w >> h;
        if (w > W && h > H)
            v.emplace_back(enevlop(w, h, i));
    }
    sort(v.begin(), v.end(), [](enevlop e1, enevlop e2) {if(e1.w != e2.w)return e1.w < e2.w; else return e1.h < e2.h; });

    if (v.empty())
    {
        cout << 0;
        return 0;
    }

    for (int i = 0; i < v.size(); i++)
        m[v[i].id] = i;

    for (int i = 0; i < v.size(); i++)
        for (int j = 0; j < i; j++)
            if (v[i].h > v[j].h && v[i].w > v[j].w && v[j].val + 1 > v[i].val)
            {
                v[i].val = v[j].val + 1;
                v[i].back = v[j].id;
            }

    for (int i = 0; i < v.size(); i++)
        if (v[i].val > v[maxindex].val)
            maxindex = i;

    cout << v[maxindex].val << '\n';
    stack<int> s;
    while (1)
    {
        s.push(v[maxindex].id);
        if (v[maxindex].back == 0)
            break;
        maxindex = m[v[maxindex].back];
    }
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}