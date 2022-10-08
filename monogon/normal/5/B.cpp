
#include <bits/stdc++.h>

#define ll long long
using namespace std;

string s;
vector<string> v;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int len = 0;
    while(getline(cin, s)) {
        v.push_back(s);
        len = max(len, (int) s.length());
    }
    int lines = v.size();
    bool l = false;
    for(int i = 0; i < len + 2; i++) {
        cout << '*';
    }
    cout << endl;
    for(int i = 0; i < lines; i++) {
        int gap = len - v[i].length();
        cout << '*';
        for(int j = 0; j < (gap + l) / 2; j++) {
            cout << ' ';
        }
        cout << v[i];
        for(int j = (gap + l) / 2; j < gap; j++) {
            cout << ' ';
        }
        cout << '*' << endl;
        if(gap % 2 == 1) {
            l = !l;
        }
    }
    for(int i = 0; i < len + 2; i++) {
        cout << '*';
    }
    cout << endl;
}