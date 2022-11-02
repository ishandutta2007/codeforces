#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
    
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(20);
    int n, h;
    cin >> n >> h;
    for (int i = 1; i < n; i++)
        cout << sqrt((double)i / n) * h << " ";
    cout << endl;
}