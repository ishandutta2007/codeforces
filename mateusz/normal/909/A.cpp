#include <bits/stdc++.h>

using namespace std;

int main() {
    
    string first, last;
    cin >> first >> last;
    
    vector<string> vec;
    string cur;
    for (int i = 0; i < first.size(); i++) {
        cur += first[i];
        vec.push_back(cur + last[0]);
    }
    
    sort(vec.begin(), vec.end());
    
    cout << vec[0] << endl;
    
    return 0;
}