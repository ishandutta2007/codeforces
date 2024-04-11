#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    int n, q, tmp;
    vector<int> x;
    cin >> n;
    while(n--){
        cin >> tmp;
        x.push_back(tmp);
    }
    sort(x.begin(), x.end());
    cin >> q;
    while(q--){
        cin >> tmp;
        cout << upper_bound(x.begin(), x.end(), tmp) - x.begin() << '\n';
    }
}