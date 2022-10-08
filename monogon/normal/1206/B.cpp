
#include <iostream>

#define ll long long
using namespace std;

const int MAX_N = 1e5 + 5;
int n;
ll a[MAX_N];
bool iszero = false, neg = true;
ll cost = 0;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            iszero = true;
            cost++;
        }else if(a[i] > 0) {
            cost += a[i] - 1;
        }else {
            cost += -1 - a[i];
            neg = !neg;
        }
    }
    if(iszero || neg) {
        cout << cost << endl;
    }else {
        cout << (cost + 2) << endl;
    }
}