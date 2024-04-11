#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxd = 4;
const int Inf = 1000000000;

int n;
int X[Maxd], Y[Maxd], A[Maxd], B[Maxd];
int cX[Maxd], cY[Maxd];
int res;

void Rotate(int ind)
{
    int nX = B[ind] - Y[ind] + A[ind];
    int nY = X[ind] - A[ind] + B[ind];
    X[ind] = nX; Y[ind] = nY;
}

bool Check2()
{
    for (int i = 0; i < Maxd; i++) {
        int ax = cX[(i + 1) % Maxd] - cX[i], ay = cY[(i + 1) % Maxd] - cY[i];
        int bx = cX[(i + 2) % Maxd] - cX[(i + 1) % Maxd], by = cY[(i + 2) % Maxd] - cY[(i + 1) % Maxd];
        int d1 = ax * ax + ay * ay, d2 = bx * bx + by * by;
        if (d1 == 0 || d1 != d2 || ax * bx + ay * by != 0)
            return false;
    }
    return true;
}

bool Check()
{
    int arr[Maxd];
    for (int i = 0; i < Maxd; i++)
        arr[i] = i;
    do {
        for (int i = 0; i < Maxd; i++) {
            cX[i] = X[arr[i]]; cY[i] = Y[arr[i]];
        }
        if (Check2()) return true;
    } while (next_permutation(arr, arr + Maxd));
    return false;
}

int main()
{
    scanf("%d", &n);
    while (n--) {
        for (int i = 0; i < Maxd; i++)
            scanf("%d %d %d %d", &X[i], &Y[i], &A[i], &B[i]);
        res = Inf;
        for (int i1 = 0; i1 < Maxd; i1++) {
            for (int i2 = 0; i2 < Maxd; i2++) {
                for (int i3 = 0; i3 < Maxd; i3++) {
                    for (int i4 = 0; i4 < Maxd; i4++) {
                        if (Check()) res = min(res, i1 + i2 + i3 + i4);
                        Rotate(3);
                    }
                    Rotate(2);
                }
                Rotate(1);
            }
            Rotate(0);
        }
        printf("%d\n", res == Inf? -1: res);
    }
    return 0;
}