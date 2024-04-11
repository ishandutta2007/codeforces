#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <ld, int> ldi;

ld x, y, z;
vector <ldi> V;

void Print(int x)
{
    switch (x) {
        case 1: printf("x^y^z\n"); break;
        case 2: printf("x^z^y\n"); break;
        case 3: printf("(x^y)^z\n"); break;
        case 5: printf("y^x^z\n"); break;
        case 6: printf("y^z^x\n"); break;
        case 7: printf("(y^x)^z\n"); break;
        case 9: printf("z^x^y"); break;
        case 10: printf("z^y^x"); break;
        case 11: printf("(z^x)^y"); break;
    }
}

int main()
{
    cin >> x >> y >> z;
    ld mx = max(max(x, y), z);
    if (mx > 1.0l) {
        if (x > 1.0l) {
            V.push_back(ldi(-(z * log(y) + log(log(x))), 1));
            V.push_back(ldi(-(y * log(z) + log(log(x))), 2));
            V.push_back(ldi(-(log(y * z) + log(log(x))), 3));
        }
        if (y > 1.0l) {
            V.push_back(ldi(-(z * log(x) + log(log(y))), 5));
            V.push_back(ldi(-(x * log(z) + log(log(y))), 6));
            V.push_back(ldi(-(log(x * z) + log(log(y))), 7));
        }
        if (z > 1.0l) {
            V.push_back(ldi(-(y * log(x) + log(log(z))), 9));
            V.push_back(ldi(-(x * log(y) + log(log(z))), 10));
            V.push_back(ldi(-(log(x * y) + log(log(z))), 11));
        }
        sort(V.begin(), V.end());
        Print(V[0].second); return 0;
    }
    if (mx == 1.0l) {
        if (x == 1.0l) Print(1);
        else if (y == 1.0l) Print(5);
        else if (z == 1.0l) Print(9);
        return 0;
    }
    V.push_back(ldi((z * log(y) + log(-log(x))), 1));
    V.push_back(ldi((y * log(z) + log(-log(x))), 2));
    V.push_back(ldi((log(y * z) + log(-log(x))), 3));
    V.push_back(ldi((z * log(x) + log(-log(y))), 5));
    V.push_back(ldi((x * log(z) + log(-log(y))), 6));
    V.push_back(ldi((log(x * z) + log(-log(y))), 7));
    V.push_back(ldi((y * log(x) + log(-log(z))), 9));
    V.push_back(ldi((x * log(y) + log(-log(z))), 10));
    V.push_back(ldi((log(x * y) + log(-log(z))), 11));
    sort(V.begin(), V.end());
    Print(V[0].second); return 0;
    return 0;
}