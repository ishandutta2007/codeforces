#include <iostream>
using namespace std;

int n, s, num;

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        s+=x;
    }
    n++;
    for (int i=1; i<=5; i++) {
        int k = s+i;
        if (k%n!=1) num++;
    }
    cout << num << endl;
}