#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100000;
const int Maxm = 1000000;
const int Maxd = 5;

struct node {
       int l, r, m;
       bool is;
       ll val[Maxd];
       int inleft;
} t[Maxm];

int n;
vector <string> com;
vector <int> arg, nums;

void Create(int v, int l, int r)
{
     if (l > r) return;
     t[v].l = l; t[v].r = r; t[v].m = l + r >> 1;
     t[v].is = false;
     for (int i = 0; i < Maxd; i++) t[v].val[i] = 0LL;
     t[v].inleft = 0;
     Create(2 * v, t[v].l, t[v].m - 1);
     Create(2 * v + 1, t[v].m + 1, t[v].r);
}

void Update(int v)
{
     int l = 2 * v, r = 2 * v + 1;
     for (int i = 0; i < Maxd; i++) t[v].val[i] = t[l].val[i];
     if (t[v].is) t[v].val[(t[v].inleft + 4) % 5] += nums[t[v].m];
     for (int i = 0; i < Maxd; i++) t[v].val[(t[v].inleft + i) % 5] += t[r].val[i];
}

void Add(int v, int x)
{
     if (x == t[v].m) {
                t[v].is = true;
                t[v].inleft++;
     } else if (x < t[v].m) {
                t[v].inleft++;
                Add(2 * v, x);
            } else Add(2 * v + 1, x);
     Update(v);
}

void Del(int v, int x)
{
     if (x == t[v].m) {
           t[v].is = false;
           t[v].inleft--;
     } else if (x < t[v].m) {
               t[v].inleft--;
               Del(2 * v, x);
            } else Del(2 * v + 1, x);
     Update(v);
}

int main()
{
    std::ios_base::sync_with_stdio(0);
    cin >> n;
    com.resize(n); arg.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> com[i];
        arg[i] = 0;
        if (com[i] != "sum") {
                cin >> arg[i];
                nums.push_back(arg[i]);
        }
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    Create(1, 0, Maxn - 1);
    for (int i = 0; i < n; i++)
        if (com[i] == "add") Add(1, lower_bound(nums.begin(), nums.end(), arg[i]) - nums.begin());
        else if (com[i] == "del") Del(1, lower_bound(nums.begin(), nums.end(), arg[i]) - nums.begin());
        else cout << t[1].val[2] << endl;
    return 0;
}