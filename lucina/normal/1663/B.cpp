#include<bits/stdc++.h>
using namespace std;

int main() {
    
    vector <int> x = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};
    int c;
    cin >> c;
    cout << *upper_bound(x.begin(), x.end(), c);
}