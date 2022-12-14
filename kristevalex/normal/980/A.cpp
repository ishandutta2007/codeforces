#include <bits/stdc++.h>
using namespace std;

string text;

int main()
    {
    cin >> text;

    int sum = 0;
    for (size_t i = 0; i < text.size(); i++)
        {
        if (text[i] == 'o') sum++;
        }

    if (sum == 0)
        cout << "YES" << endl;
    else if ((text.size()/sum)*sum == text.size())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;

    }