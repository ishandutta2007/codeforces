#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#define PI 3.1415926535897932
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    double asi = sin(PI / n);
    cout << setprecision(9) << m * asi / (1 - asi);
}