#include <bits/stdc++.h>
using namespace std;

int n, m, q;
map <int, int> Z, O;
bool bad;

void Add(map <int, int> &M, int key, int val)
{
    auto it = M.lower_bound(key);
    if (it != M.end())
        if (it->second >= val) return;
        else if (it->first == key) it++;
    while (it != M.begin()) {
        it--;
        if (val >= it->second) M.erase(it++);
        else break;
    }
    M.insert(make_pair(key, val));
}

bool Good(map <int, int> &M, int key, int val)
{
    auto it = M.lower_bound(key);
    if (it == M.end()) return true;
    return val > it->second;
}

int main()
{
    scanf("%d %d %d", &n, &m, &q);
    while (q--) {
        int x, y; scanf("%d %d", &x, &y);
        int r = (x - 1) / 2 + 1;
        int c = (y - 1) / 2 + 1;
        int col = (x - 1) % 2;
        if (col == 0) {
            if (!Good(Z, r, c)) bad = true;
            Add(O, n + 1 - r, m + 1 - c);
        } else {
            if (!Good(O, n + 1 - r, m + 1 - c)) bad = true;
            Add(Z, r, c);
        }
        printf("%s\n", bad? "NO": "YES");
    }
    return 0;
}