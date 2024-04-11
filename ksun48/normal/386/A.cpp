#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    pair<int,int> a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].first *= -1;
        a[i].second = i+1;
    }
    sort(a, a+n);
    cout << a[0].second << " " << -a[1].first << endl;
    return 0;
}