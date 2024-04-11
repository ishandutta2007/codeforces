
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int a, sum;

int solve(int a, int b) {
    int sum = 0;
    while(a > 0) {
        sum += (a % b);
        a /= b;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> a;
    for(int b = 2; b < a; b++) {
        sum += solve(a, b);
    }
    int g = gcd(sum, a - 2);
    cout << sum/g << "/" << (a - 2)/g << endl;
}