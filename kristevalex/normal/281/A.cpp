#include <bits/stdc++.h>
using namespace std;


string text;


int main()
    {
    cin >> text;

    text[0] = (text[0] >= 'a' && text[0] <= 'z')? text[0]+('A'-'a'):text[0];

    cout << text;
    return 0;
    }