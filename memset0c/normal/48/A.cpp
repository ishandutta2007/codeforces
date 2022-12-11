#include <bits/stdc++.h>
#define ll long long
using namespace std;

int a, b, c;
string sa, sb, sc;
bool win(int a, int b, int c) { return ((a == 1 && b == 3 && c == 3) || (a == 2 && b == 1 && c == 1) || (a == 3 && b == 2 && c == 2)); }
int main() {
    cin >> sa >> sb >> sc;
    a = sa == "scissors" ? 1 : sa == "rock" ? 2 : 3;
    b = sb == "scissors" ? 1 : sb == "rock" ? 2 : 3;
    c = sc == "scissors" ? 1 : sc == "rock" ? 2 : 3;
    if (win(a, b, c)) puts("F");
    else if (win(b, a, c)) puts("M");
    else if (win(c, a, b)) puts("S");
    else puts("?");
    return 0;
}
// dasfkjfisjisdjsgiojosgsdgfgsfg