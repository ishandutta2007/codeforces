#include <bits/stdc++.h>
using namespace std;

int n, num[10];

int main() {
    cin >> n;
    for (int i=0; i<n; i++) {
        char c; cin >> c;
        if (c == '2') num[2]++;
        else if (c == '3') num[3]++;
        else if (c == '4') num[2]+=2, num[3]++;
        else if (c == '5') num[5]++;
        else if (c == '6') num[5]++, num[3]++;
        else if (c == '7') num[7]++;
        else if (c == '8') num[7]++, num[2]+=3;
        else if (c == '9') num[7]++, num[3]+=2, num[2]++;
    }
    for (int i=7; i>0; i--)
        for (int j=0; j<num[i]; j++)
            cout << i;
}