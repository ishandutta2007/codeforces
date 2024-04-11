
#include <iostream>

using namespace std;

int t;
long long n;

long long numCards(long long h) {
    return (3 * h * h + h) / 2;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        long long h = 0;
        while(numCards(h) <= n) h++;
        long long pyramids = 0;
        for(; h > 0; h--) {
            while(n >= numCards(h)) {
                n -= numCards(h);
                pyramids++;
            }
        }
        cout << pyramids << '\n';
    }
}