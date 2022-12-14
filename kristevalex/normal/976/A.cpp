#include <bits/stdc++.h>
using namespace std;

int n;

string field;

int main()
{
    cin >> n >> field;

    int nulls = 0;

    if (field[0] == '0')
        {
        cout << 0 << endl;
        return 0;
        }

    for (size_t i = 0; i < n; i++)
        {
        if (field[i] == '0') nulls++;
        }

    cout << 1;
    for (size_t i = 0; i < nulls; i++)
        cout << 0;

    return 0;
}