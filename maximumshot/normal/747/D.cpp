#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 200005;

int n, k;
int t[N];

int main() {

    scanf("%d %d", &n, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &t[i]);
        if(t[i] < 0) k--;
    }

    if(k < 0) {
        puts("-1");
        return 0;
    }

    int start = 0;

    while(start <= n && t[start] >= 0) start++;

    if(start > n) {
        puts("0");
        return 0;
    }

    vec< pii > seg;

    for(int i = start;i <= n;i++) {
        if(t[i] < 0) continue;
        int j = i;
        while(j <= n && t[j] >= 0) j++; j--;
        seg.push_back( make_pair(i, j) );
        i = j;
    }

    if(seg.empty()) {
        puts("1");
        return 0;
    }

    if(seg.back().second < n) {
        vec< int > mas;
        for(auto it : seg) mas.push_back(it.second - it.first + 1);
        sort(ALL(mas));
        int sum = 0, cnt = 0;
        for(int i = 0;i < (int)mas.size();i++) {
            if(sum + mas[i] <= k) {
                sum += mas[i];
                cnt++;
            }else {
                break;
            }
        }
        printf("%d\n", (int)seg.size() * 2 + 1 - 2 * cnt);
    }else {
        int res = inf;

        if(seg.back().second - seg.back().first + 1 <= k) {
            k -= (seg.back().second - seg.back().first + 1);
            vec< int > mas;
            for(int it = 0;it + 1 < (int)seg.size();it++) {
                mas.push_back( seg[it].second - seg[it].first + 1 );
            }
            sort(ALL(mas));
            int sum = 0, cnt = 0;
            for(int i = 0;i < (int)mas.size();i++) {
                if(sum + mas[i] <= k) {
                    sum += mas[i];
                    cnt++;
                }else {
                    break;
                }
            }
            res = min(res, 2 * (int)seg.size() - 1 - 2 * cnt );
            k += (seg.back().second - seg.back().first + 1);
        }

        {
            vec< int > mas;
            for(int it = 0;it + 1 < (int)seg.size();it++) {
                mas.push_back( seg[it].second - seg[it].first + 1 );
            }
            sort(ALL(mas));
            int sum = 0, cnt = 0;
            for(int i = 0;i < (int)mas.size();i++) {
                if(sum + mas[i] <= k) {
                    sum += mas[i];
                    cnt++;
                }else {
                    break;
                }
            }
            res = min(res, 2 * (int)seg.size() - 2 * cnt);
        }

        printf("%d\n", res);
    }

    return 0;
}