#include <bits/stdc++.h>
using namespace std;

const int lim = 1000000001;
const int Maxb = 30;

int n;
int lastans;
unordered_map <int, int> M;
int nil;

void Insert(int x)
{
    for (int i = x; i < 1 << Maxb; i += i & -i) {
        auto it = M.find(i);
        if (it == M.end()) M.insert(make_pair(i, 1));
        else it->second++;
    }
}

int Get(int x)
{
    int res = 0;
    for (int i = x; i > 0; i -= i & -i) {
        auto it = M.find(i);
        if (it != M.end()) res += it->second;
    }
    return res;
}

int getLow(int val)
{
    int res = 0;
    int acc = 0;
    for (int i = Maxb - 1; i >= 0; i--) {
        auto it = M.find(res + (1 << i));
        int add = it == M.end()? 0: it->second;
        if (nil + res + (1 << i) - 1 - acc - add < val) {
            res += 1 << i;
            acc += add;
        }
    }
    return res + 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int T; scanf("%d", &T);
        int ind = getLow(T + 1);
        Insert(ind);
        ind = getLow(T);
        Insert(ind);
        nil++;
        int k; scanf("%d", &k);
        while (k--) {
            int x; scanf("%d", &x);
            x = (x + lastans) % lim;
            lastans = nil + x - Get(x + 1);
            printf("%d\n", lastans);
        }
    }
    return 0;
}