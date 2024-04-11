#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5  + 10;
void rte () {
    exit(1);
}

int main () {
    string s;

    cin >> s;

    printf("%d\n", (s.back() - '0') % 2);
}