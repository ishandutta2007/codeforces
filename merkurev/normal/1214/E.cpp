#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif




int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    vector <pair <int, int>> v;

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        v.emplace_back(x, i);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    vector <pair <int, int>> ans;
    vector <int> st;

    for (int i = 0; i < (int) v.size(); i++)
    {
        st.push_back(2 * v[i].second + 1);
        if (st.size() >= 2)
            ans.emplace_back(st[(int) st.size() - 2], st.back());
    }


    int cd = n;
    for (int i = 0; i < (int) v.size(); i++)
    {
        if (i + v[i].first - 1 < (int) v.size())
        {
            cd = v[i].first;
            ans.emplace_back(2 * v[i].second, 2 * v[i + cd - 1].second + 1);
            st.push_back(2 * v[i].second);
            continue;
        }
        while (v[i].first < cd)
        {
            cd--;
            st.pop_back();
        }
        st.push_back(2 * v[i].second);
        ans.emplace_back(st[(int) st.size() - 2], st.back());

    }


    for (auto p : ans)
        printf("%d %d\n", p.first + 1, p.second + 1);

    return 0;
}