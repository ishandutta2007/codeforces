#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, a[100010];
map<int, vector<int> > mp;
int x[100010], p[100010], cnt;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        mp[a[i]].push_back(i);
    }
    for (typeof(mp.begin()) it = mp.begin(); it != mp.end(); it++) {
        int d = 0;
        for (int i=1; i<(it->second).size(); i++) {
            if (i != 1 && it->second[i] - it->second[i-1] != d) {
                d = -1; break;
            } else d = it->second[i] - it->second[i-1];
        }
        if (d != -1) { x[cnt] = it->first, p[cnt] = d, cnt++; }
    }
    printf("%d\n", cnt);
    for (int i=0; i<cnt; i++) printf("%d %d\n", x[i], p[i]);
}