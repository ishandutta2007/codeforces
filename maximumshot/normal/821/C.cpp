#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    int cur = 1;

    set< int > q;
    vec< int > st;

    int n;

    scanf("%d", &n);

    char buff[10];

    int res = 0;

    for(int x, iter = 0;iter < n+n;iter++) {
        scanf("%s", buff);
        if(buff[0] == 'a') {
            scanf("%d", &x);
            st.push_back(x);
        }else {
            if(!st.empty() && st.back() != cur) {
                res++;
                while(!st.empty()) {
                    q.insert(st.back());
                    st.pop_back();
                }
            }
            if(!st.empty()) {
                st.pop_back();
            }else {
                q.erase(q.begin());
            }
            cur++;
        }
    }

    printf("%d\n", res);

    return 0;
}