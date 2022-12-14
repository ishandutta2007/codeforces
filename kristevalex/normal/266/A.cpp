#include <bits/stdc++.h>
using namespace std;

int n;
string text;


int main()
    {
    cin >> n >> text;

    int delta = 0;

    for (int i = 0; i < n-1; i++)
        {
        if (text[i] == text[i+1]) delta++;
        }

    cout << delta;
    return 0;
    }