#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
    int n;
    int num=0;
    cin >> n;
    for (int i=0; i<n; i++) {
        int k, a;
        cin >> k >> a;
        int m=k+1;
        for (int i=4; i<a; i*=4) m++;
        num=max(num, m);
    }
    cout << num << endl;
}