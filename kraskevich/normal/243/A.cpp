#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <deque>
#include <cassert>

using namespace std;


#define MP make_pair
#define PB push_back
#define PII pair<int, int>
#define PLL pair<long long, long long>
#define F first
#define S second
#define WAIT int w; cin >> w
#define ALL(x) x.begin(), x.end()


const int N = 100 * 1000;
int a[N];
bool was[2 * 1000 * 1000 + 1];
int nxt[N][21];

bool bit(int mask, int i)
{
    return ((mask & (1 << i)) ? 1 : 0);
}

struct state
{
    int ind, mask;
    state() {}
    state(int _i, int _m): ind(_i), mask(_m) {}
};

bool cmp(state a, state b)
{
    return a.ind < b.ind;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    for (int i = 0; i < 2 * 1000 * 1000 + 1; ++i)
        was[i] = false;
    
    for (int bt = 0; bt <= 20; ++bt)
    {
        int last = -1;
        for (int i = n - 1; i >= 0; --i)
        {
            if (bit(a[i], bt))
                last = i;
            nxt[i][bt] = last;
        }
    }
    
    for (int i = 0; i < n; ++i)
    {
        vector<state> st;
        for (int bt = 0; bt <= 20; ++bt)
            if (nxt[i][bt] != -1)
                st.push_back(state(nxt[i][bt], bt));
        
        sort(st.begin(), st.end(), cmp);
        
        int cur = 0;
        for (int j = 0; j < st.size(); ++j)
        {
            cur = (cur | (1 << st[j].mask));
            if (j == st.size() - 1 || st[j].ind != st[j + 1].ind)
                was[cur] = true;
        }
    }
    
    int res = 0;
    for (int i = 1; i < 2 * 1000 * 1000 + 1; ++i)
        if (was[i])
            ++res;
    for (int i = 0; i < n; ++i)
        if (!a[i])
        {
            ++res;
            break;
        }
    
    cout << res;
    
    return 0;
}