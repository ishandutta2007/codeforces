#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const int CMax = 100002;
const long long CInf = 1000000002;

long long n, k, A[CMax], maxLength, currLength;

int main() {
    scanf("%I64d %I64d", &n, &k);

    for (int i = 0; i < n; i++) {
        scanf("%I64d", &A[i]);
        if (i == 0 || A[i - 1] != A[i]) {
            currLength++;
        } else {
            currLength = 1;
        }
        if (currLength > maxLength) maxLength = currLength;
    }

    printf("%I64d\n", maxLength);
    return 0;
}