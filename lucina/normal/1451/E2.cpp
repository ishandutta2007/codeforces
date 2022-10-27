#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
int ans[nax];
int xor_val[nax];
int n;

void answer() {
    printf("! ");
    for (int i = 1 ; i <= n ; ++ i)
        printf("%d ", ans[i]);
    puts("");
    exit(0);
}

int main() {
    scanf("%d", &n);
    map <int, vector <int> > setik;

    for (int i = 2 ; i <= n ; ++ i) {
        printf("XOR %d %d\n", 1, i);
        fflush(stdout);
        scanf("%d", xor_val + i);
        setik[xor_val[i]].push_back(i);
    }

    if (setik.count(0)) {
        int where = setik[0][0];
        printf("AND %d %d\n", 1, where);
        fflush(stdout);
        scanf("%d", &ans[1]);

        for (int i = 2 ; i <= n ; ++ i)
            ans[i] = ans[1] ^ xor_val[i];
        answer();
    }

    if (setik.size() != n - 1) {
        int b, c;
        for (auto &it : setik) {
            if (it.second.size() >= 2) {
                b = it.second[0];
                c = it.second[1];
                break;
            }
        }
        printf("AND %d %d\n", b, c);
        fflush(stdout);
        scanf("%d", &ans[b]);
        ans[1] = ans[b] ^ xor_val[b];

        for (int i = 2 ; i <= n ; ++ i)
            ans[i] = ans[1] ^ xor_val[i];
        answer();
    }

    int b = 0, c = 0;

    const int C = n - 1;

    for (int i = 0 ; i < n ; ++ i) {
        if (setik.count(i) && setik.count(C ^ i)) {
            b = setik[i][0];
            c = setik[C ^ i][0];
        }
    }

    assert(b && c);
    assert(b != c);

    int a = 1;

    printf("AND %d %d\n", a, b);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    printf("AND %d %d\n", a, c);
    fflush(stdout);
    int y;
    scanf("%d", &y);
    int z = xor_val[b];
    int w = xor_val[c];

    /**
    b & c = 0
    a & b = x
    a & c = y
    a ^ b = z
    a ^ c = w

    a + b
    a + c
    b + c
    */

    int apb = z + 2 * x;
    int apc = w + 2 * y;
    int bpc = n - 1;

    ans[1] = (apb + apc - bpc) >> 1;
    for (int i = 2 ; i <= n ; ++ i)
        ans[i] = ans[1] ^ xor_val[i];
    answer();


}