#include <bits/stdc++.h>
using namespace std;

bool win(string a, string b) {
    if (a == "rock" && b == "scissors" ||
        a == "scissors" && b == "paper" ||
        a == "paper" && b == "rock") return true;
    return false;
}

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    if (win(a, b) && win(a, c) && b == c)
        puts("F");
    else if (win(b, a) && win(b, c) && a == c)
        puts("M");
    else if (win(c, a) && win(c, b) && a == b)
        puts("S");
    else
        puts("?");
    return 0;
}