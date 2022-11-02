#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cassert>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

#define MP make_pair
#define F first
#define S second
#define pii pair<int, int>

typedef long long i64;
const double eps = 1e-7;
const int inf = (int)1e9;



//Reading and printing arrays and vectors//
template<class T> void read(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cin >> a[i];
}

template<class T> void read(T a[], int n)
{
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

template<class T> void print(vector<T> a)
{
    for (int i = 0; i < a.size(); ++i)
        cout << a[i] << " ";
    cout << "\n";
}

template<class T> void print(T a[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
    cout << "\n";
}
//-----------------------------------------//





const int sqr = 333;
const int N = 1000 * 100 + 4;

int a[N], bl[N];

void init()
{
    for (int i = 0; i < N; ++i)
        bl[i] = i / sqr;
}

struct ask
{
    int l, r, id;
    ask() {}
    ask(int _l, int _r, int _id): l(_l), r(_r), id(_id) {}
};

bool cmp(ask a, ask b)
{
    return bl[a.l] < bl[b.l] || bl[a.l] == bl[b.l] && a.r < b.r;
}

ask t[N];
int cnt[N];

void initcnt()
{
    for (int i = 0; i < N; ++i)
        cnt[i] = 0;
}

int ans[N];
bool proc[N / sqr + 1];

void initproc()
{
    for (int i = 0; i < N / sqr + 1; ++i)
        proc[i] = false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    init();
    
    int n, m;
    cin >> n >> m;
    
    read(a, n);
    
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l, --r;
        t[i] = ask(l, r, i);
    }
    
    sort(t, t + m, cmp);
    
    int res = 0;
    
    for (int i = 0; i < m; ++i)
    {
        if (!i || bl[t[i].l] != bl[t[i-1].l])
            initcnt(), initproc(), res = 0;
        
        int curl = bl[t[i].l] + 1, curr = bl[t[i].r] - 1;
        
        for (int j = curl; j <= curr; ++j)
        {
            if (proc[j])
                continue;
            for (int t = sqr * j; t < min(n, sqr * (j + 1)); ++t)
            {
                if (a[t] >= N)
                    continue;
                if (cnt[a[t]] == a[t])
                    --res;
                ++cnt[a[t]];
                if (cnt[a[t]] == a[t])
                    ++res;
            }
            proc[j] = true;
        }
        
        if (curl <= curr + 1)
        {
            for (int j = t[i].l; j < min(n, sqr * curl); ++j)
            {
                if (a[j] >= N)
                    continue;
                if (cnt[a[j]] == a[j])
                    --res;
                ++cnt[a[j]];
                if (cnt[a[j]] == a[j])
                    ++res;
            }
        
            for (int j = (curr + 1) * sqr; j <= t[i].r; ++j)
            {
                if (a[j] >= N)
                    continue;
                if (cnt[a[j]] == a[j])
                    --res;
                ++cnt[a[j]];
                if (cnt[a[j]] == a[j])
                    ++res;
            }
            
            ans[t[i].id] = res;
            
            for (int j = t[i].l; j < min(n, sqr * curl); ++j)
            {
                if (a[j] >= N)
                    continue;
                if (cnt[a[j]] == a[j])
                    --res;
                --cnt[a[j]];
                if (cnt[a[j]] == a[j])
                    ++res;
            }
            
            for (int j = (curr + 1) * sqr; j <= t[i].r; ++j)
            {
                if (a[j] >= N)
                    continue;
                if (cnt[a[j]] == a[j])
                    --res;
                --cnt[a[j]];
                if (cnt[a[j]] == a[j])
                    ++res;
            }
        }
        else
        {
            for (int j = t[i].l; j <= t[i].r; ++j)
            {
                if (a[j] >= N)
                    continue;
                if (cnt[a[j]] == a[j])
                --res;
                ++cnt[a[j]];
                if (cnt[a[j]] == a[j])
                    ++res;
            }
            ans[t[i].id] = res;
            
            for (int j = t[i].l; j <= t[i].r; ++j)
            {
                if (a[j] >= N)
                    continue;
                if (cnt[a[j]] == a[j])
                --res;
                --cnt[a[j]];
                if (cnt[a[j]] == a[j])
                    ++res;
            }
        }
    }
    
    for (int i = 0; i < m; ++i)
        cout << ans[i] << "\n";
    
    return 0;
}