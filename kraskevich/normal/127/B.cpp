#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; ++i)
            cin >> a[i];
    sort(a, a + n);
    int pairs = 0;
    int k = 1;
    for(int i = 1; i < n; ++i)
            if(a[i] == a[i - 1])
                    k++;
            else {
                 pairs += k / 2;
                 k = 1;
            }
    pairs += k / 2;
    cout << pairs / 2;
    cin >> n;
    return 0;
}