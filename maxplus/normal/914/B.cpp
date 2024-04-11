#include <iostream>

using namespace std;

int main()
{
    int res = 0, n, a, A[100001]{};
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a, ++A[a];
    for (int i = 0; i < 100001; ++i)
        if (A[i] & 1)
            res = 1;
    cout << (const char*[]){"Agasa", "Conan"}[res];
    return 0;
}