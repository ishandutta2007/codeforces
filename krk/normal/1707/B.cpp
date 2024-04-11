#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
vector <int> a;
int zers;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        a.clear(); zers = 0;
        for (int i = 0; i < n; i++) {
            int num; scanf("%d", &num);
            if (num == 0) zers++;
            else a.push_back(num);
        }
        while (a.size() + zers > 1) {
            vector <int> b;
            int nzers = 0;
            if (zers > 0) nzers += zers - 1;
            if (zers > 0 && a.size() > 0) b.push_back(a[0]);
            for (int i = 1; i < a.size(); i++)
                if (a[i - 1] == a[i]) nzers++;
                else b.push_back(a[i] - a[i - 1]);
            sort(b.begin(), b.end());
            zers = nzers; a = b;
        }
        printf("%d\n", zers? 0: a[0]);
    }
    return 0;
}