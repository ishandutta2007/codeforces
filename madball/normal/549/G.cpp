#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
    /*ifstream in("input.txt");
    ofstream out("output.txt");*/

    ll n, i;
    cin >> n;
    vector<ll> money(n);
    for (i = 0; i < n; i++) {
        cin >> money[i];
        money[i] -= n - i;
    }

    sort(money.begin(), money.end());

    bool succ = true;
    for (i = 0; i < n; i++) {
        money[i] += n - i;
        if ((i) && (money[i] < money[i - 1]))
            succ = false;
    }
    if (succ)
        for (i = 0; i < n; i++)
            cout << money[i] << ' ';
    else
        cout << ":(";

    return 0;
}