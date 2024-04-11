#include <iostream>
using namespace std;

int main()
{
    int n, is, jump;
    cin >> n;
    is = (n+1) / 2;
    if (n % 2) jump = -1;
    else jump = 1;
    do {
        cout << is;
        if (is < n) cout << " ";
        else break;
        is += jump;
        if (jump > 0) jump = -jump -1;
        else jump = -jump + 1;
    } while (true);
    cout << endl;
    return 0;
}