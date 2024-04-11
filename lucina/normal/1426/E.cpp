#include<bits/stdc++.h>
using namespace std;
int n;
int a[4];
int b[4];

int main() {
    cin >> n;
    for (int i = 1 ; i <= 3 ; ++ i)
        cin >> a[i];
    for (int i = 1 ; i <= 3 ; ++ i)
        cin >> b[i];
    /**
    rock scissor paper respectively
    rock scissor paper
    a1 => b2
    a2 => b3
    a3 => b1
    */
    /**
        a1->b1
        a2->b2
        a3->b3
        a b a
        b a b
    */

    int ans_max = min(a[1], b[2]) + min(a[2], b[3]) + min(a[3], b[1]);

    int cnt_alive = 0;
    int ans_min = 0;

    for (int i = 1 ; i <= 3 ; ++ i) {
        int bar = a[i];
        bar -= b[i];
        int lf = i - 1;
        if (lf == 0) lf = 3;
        bar -= b[lf];
        ans_min = max(ans_min, bar);
    }

    cout << ans_min << ' ' << ans_max << '\n';
}
/**
319
10      53      256
182     103     34
 0       0       222
                153
                119
*/