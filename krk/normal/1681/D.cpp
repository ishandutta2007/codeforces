#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef pair <int, ull> iull;

int n;
ull x;
map <ull, int> M;

int Digs(ull x)
{
    int res = 0;
    while (x) {
        res++;
        x /= 10;
    }
    return res;
}

int main()
{
    cin >> n >> x;
    M[x] = 0;
    priority_queue <iull> Q; Q.push(iull(0, x));
    while (!Q.empty()) {
        int d = -Q.top().first;
        ull x = Q.top().second; Q.pop();
        if (M[x] != d) continue;
        if (Digs(x) == n) {
            printf("%d\n", d);
            return 0;
        }
        ull num = x;
        while (num) {
            int cur = num % ull(10);
            num /= 10;
            if (cur > 1) {
                ull u = x * cur;
                auto it = M.find(u);
                if (it == M.end()) {
                    M.insert(make_pair(u, d + 1));
                    Q.push(iull(-(d + 1), u));
                }
            }
        }
    }
    printf("-1\n");
    return 0;
}