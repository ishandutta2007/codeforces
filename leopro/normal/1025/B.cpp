#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    unordered_set<int> dividers{0};
    for (int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;
        unordered_set<int> new_dividers;
        for (int d : dividers) new_dividers.insert(__gcd(a, d));
        for (int d : dividers) new_dividers.insert(__gcd(b, d));
        dividers = new_dividers;
        while (dividers.size() > 30) dividers.erase(dividers.begin());
    }
    int max = 1;
    for (int x : dividers) max = ::max(max, x);
    cout << (max == 1 ? -1 : max);
}