#include <bits/stdc++.h>

using namespace std;

vector<int> month{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
vector<string> names{"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);    
    string a, b;
    cin >> a >> b;
    for (int st = 0; st < 7; st++) {
        vector<string> cur;
        int d = st;
        for (int i = 0; i < month.size(); i++) {
            cur.push_back(names[d % 7]);
            d += month[i];            
        }    
        for (int i = 0; i + 1 < month.size(); i++)
            if (cur[i] == a && cur[i + 1] == b) {
                cout << "YES" << endl;
                return 0;
            }
    }
    cout << "NO" << endl;
    return 0;
}