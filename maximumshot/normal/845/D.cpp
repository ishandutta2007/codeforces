#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    int n;

    scanf("%d", &n);

    stack< int > s1, s2;

    s1.push(inf);
    s2.push(1);

    int r = 0;
    int v = inf;

    for(int i = 0;i < n;i++) {
        int t;
        scanf("%d", &t);
        if(t == 1) {
            scanf("%d", &v);
            while(s1.top() < v) {
                s1.pop();
                r++;
            }
        }else if(t == 2) {
            while(s2.top() == 0) {
                s2.pop();
                r++;
            }
        }else if(t == 3) {
            int x;
            scanf("%d", &x);
            s1.push(x);
            while(s1.top() < v) {
                s1.pop();
                r++;
            }
        }else if(t == 4) {
            s2.push(1);
        }else if(t == 5) {
            s1.push(inf);
        }else { // t == 6
            s2.push(0);
        }
    }

    printf("%d\n", r);

    return 0;
}