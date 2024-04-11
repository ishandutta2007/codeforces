#include <iostream>
#include <algorithm>
using namespace std;

string s, t;
int n;

int main() {
    cin >> s >> n;
    for (int i=0; i<s.length(); i++) {
        if ((int)(tolower(s[i]))<n+97) t+=toupper(s[i]);
        else t+=tolower(s[i]);
    }
    cout << t << endl;
}