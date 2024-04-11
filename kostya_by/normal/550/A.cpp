#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s; cin >> s;
    bool flagAB = false;
    bool flagBA = false;

    bool answer = false;
    for (int i = 0; i + 1 < s.size(); i++) {
        if (flagAB && s.substr(i, 2) == "BA") {
            answer = true;
        }
        if (flagBA && s.substr(i, 2) == "AB") {
            answer = true;
        }
        
        if (i == 0) {
            continue;
        }
        
        if (s.substr(i - 1, 2) == "AB") {
            flagAB = true;
        }
        if (s.substr(i - 1, 2) == "BA") {
            flagBA = true;
        } 
    }

    cout << (answer ? "YES" : "NO") << "\n";
}

int main() {
    int cases; cases = 1;
    for (int i = 0; i < cases; i++) {
        solve(); 
    }
}