#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int CMax = 100002;

int n, k, c;
long long A[CMax], tsum, tpsum;
vector <int> B;

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        tsum += A[i];
    }


    if (tsum % k > 0) {
        printf("No\n");
        return 0;
    }

    tsum /= k;

    for (int i = 0; i < n; i++) {
        tpsum += A[i];
        c++;
        if (tpsum == tsum) {
            B.push_back(c);
            tpsum = 0;
            c = 0;
        } else if (tpsum > tsum) {
            printf("No\n");
            return 0;
        }
    }

    printf("Yes\n");
    for (int i = 0; i < k; i++) {
        if (i > 0) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");
}