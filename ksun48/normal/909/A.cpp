#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    string a, b;
    cin >> a >> b;
    vector<string> c;
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b.size(); j++){
            c.push_back(a.substr(0,i+1) + b.substr(0,j+1));
        }
    }
    sort(c.begin(), c.end());
    cout << c[0] << endl;
}