#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

set< pair<int, int> > e;
int test, n, ooo, x, y, a[100011], f[100011], d[100011], v[100011], g[100011];
vector<int> c[100011];

bool check(int bc) {
    if (!ooo)
        return true;
    
    auto itr = e.end();
    --itr;
    //printf("xx %d\n", itr->first);
    
    if (itr->first * 2 > ooo)
        return false;

    int cnt = 0;
    for (int i = 1; i <= n + 1; i++)
        if (d[i] < c[i].size()) {
            int l = c[i].size();
            for (int j = d[i]; j < l; j++)
                g[++cnt] = c[i][j];
        }
    
    for (int i = 1; i <= y - x; i++) {
        int j = i + cnt / 2;
        if (j > cnt)
            j -= cnt;
        f[g[j]] = a[g[i]];
    }
    return true;
}

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d%d%d", &n, &x, &y);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            c[a[i]].push_back(i);
            f[i] = 0;
        }
        e.clear();
        int bc = 0;
        for (int i = 1; i <= n + 1; i++)
            if (!c[i].size())
                bc = i;
            else
                e.insert(make_pair(c[i].size(), i)), d[i] = 0,
                v[i] = c[i].size();
        
        bool ok = false;
        
        ooo = n;
        
        for (int i = 1; i <= x; i++) {
            auto itr = e.end();
            --itr;
            int idx = itr->second;
            f[c[idx][d[idx]++]] = idx;
            e.erase(itr);
            --v[idx];
            if (v[idx])
                e.insert(make_pair(v[idx], idx));
            --ooo;
        }
        
        
        if (!check(bc)) 
            for (int i = 1; i <= n - y; i++) {
                auto itr = e.end();
                --itr;
                int idx = itr->second;
                //f[c[idx][d[idx]++] = bc;
                e.erase(itr);
                --v[idx];
                if (v[idx])
                    e.insert(make_pair(v[idx], idx));
                d[idx]++;
                --ooo;
                if (check(bc)) {
                    ok = true;
                    break;
                }
            }
        else 
            ok = true;
        
        if (!ok) 
            printf("NO\n");
        else {
            printf("YES\n");
            for (int i = 1; i <= n; i++)
                if (!f[i])
                    printf("%d ", bc);
                else
                    printf("%d ", f[i]);
            printf("\n");
        }
        for (int i = 1; i <= n + 1; i++)
            c[i].clear();
        
    }
}