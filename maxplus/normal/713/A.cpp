#include <iostream>

using namespace std;

char c;
int am[1 << 20];

int readm()
{
    int msk = 0;
    while (c = cin.get(), c != '\n')
        msk = msk * 2 + (c - '0') % 2;
    return msk;
}

int main()
{
    int q;
    cin >> q;
    cin.get();
    while (q--)
    {
        if (cin >> c, c == '+' && cin.get())
            ++am[readm()];
        else if (c == '-')
            --am[readm()];
        else
            cout << am[readm()] << '\n';
    }
    return 0;
}