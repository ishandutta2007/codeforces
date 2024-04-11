#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string S;
    getline(cin, S);
    vector<bool> T(26, false);
    for (char s:S) {
        if (s >= 'a' && s <= 'z') T[s-'a'] = true;
    }
    cout << count(T.begin(),T.end(),true) << endl;
}