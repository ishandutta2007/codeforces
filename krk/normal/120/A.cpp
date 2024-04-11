#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

string s;
int r;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> s >> r;
    if (s == "front" && r == 1 || s == "back" && r == 2) cout << "L\n";
    else cout << "R\n";
    return 0;
}