# include <iostream>
# include <cstdio>
# include <cstring>
# include <set>
# include <functional>
using namespace std;

multiset<int,greater<int> > smax;
multiset<int> smin;

const int MAXN = 100010;

int n, s, l;
int q[MAXN];
int a[MAXN];
int f[MAXN];

int main() {
    scanf("%d%d%d", &n, &s, &l);
    for(int i = 1; i <= n; ++i) 
        scanf("%d", &a[i]);
    memset(f, 0x3f, sizeof(f));
    f[0] = 0;
    for(int i = 1; i < l; ++i) {
        smax.insert(a[i]);
        smin.insert(a[i]);
    }
    int h = 0, t = 0, pt = 1;
    for(int i = l; i <= n; ++i) {
        while(h < t && f[q[t -1]] >= f[i-l]) --t;
        q[t++] = i - l;
        smax.insert(a[i]);
        smin.insert(a[i]);
        while(*smax.begin() - *smin.begin() > s) {
            smax.erase(smax.find(a[pt]));
            smin.erase(smin.find(a[pt]));
            pt += 1;
        }
        while(h < t && q[h] < pt - 1) ++h;
        if(h < t) f[i] = f[q[h]] + 1;
    }
    if(f[n] >= 0x3f3f3f3f) {
        cout << -1 << endl;
    } else {
        cout << f[n] << endl;
    }
    return 0;
}