#include <iostream>
#include <algorithm>
using namespace std;

string s;
int num, numi;

int main() {
    int n;
    cin >> n;
    cin >> s;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='I') numi++;
        else if (s[i]=='A') num++;
    }
    if (numi) {
        cout << (numi==1) << endl;
    }
    else cout << num << endl;
}