#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    a -= '0';
    b -= '0';
    c -= '0';
    d -= '0';
    e -= '0';
    int64_t n = (((a * 10 + c) * 10 + e) * 10 + d) * 10 + b;
    printf("%05d", int((((n * n * n) % 100000) * n * n) % 100000));
    return 0;
}