#include<algorithm>
#include<cstdio>
#include<iostream>


using namespace std;

int v[26] = {}, n;
char ch;

int main() {
    cin >> n;
    while (n--) {
        cin >> ch;
        if ('A' <= ch && ch <= 'Z') {
            v[ch - 'A']++;
        } else if ('a' <= ch && ch <= 'z') {
            v[ch - 'a']++;
        } else {
            cout << "unknown character" << endl;
        }
    }
    for (int i = 0; i < 26; i++) {
        if (!v[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}