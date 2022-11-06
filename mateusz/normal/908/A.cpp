#include <bits/stdc++.h>

using namespace std;

const char vowels[] = {'a', 'e', 'i', 'o', 'u'};

bool isVowel(char c) {
    for (int i = 0; i < 5; i++) {
        if (c == vowels[i]) {
            return true;
        }
    }
    return false;
}

bool isNotEven(char c) {
    if (c < '0' || c > '9') {
        return false;
    }
    int v = c - '0';
    return v % 2;
}

int main() {
    
    string s;
    cin >> s;
    
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        if (isVowel(s[i]) || isNotEven(s[i])) {
            ans++;
        }
    }
    
    cout << ans << endl;
    
    return 0;
}