#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int a = l1, b = r2;
        if (a == b)
            b--;
        cout << a << ' ' << b<<endl;
    }
    return 0;
}