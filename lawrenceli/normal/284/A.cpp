#include <iostream>
#include <algorithm>
using namespace std;

int p;
int num;

int main() {
    cin >> p;
    for (int i=1; i<=p; i++) {
        int x=i;
        bool b = false;
        for (int j=1; j<p-1; j++) {
            if ((x-1) % p == 0) b = true;
            x=(x*i)%p;
        }
        if (!b && (x-1) % p == 0) num++;
    }
    cout << num << endl;
}