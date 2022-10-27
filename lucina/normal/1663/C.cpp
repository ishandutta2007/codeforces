#include<bits/stdc++.h>
using namespace std;
int n;
int a[155555];

int main() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    cout << accumulate(a + 1, a + 1 + n, 0);

}