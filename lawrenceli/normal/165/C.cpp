#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int k;
string s;
vector<int> v;
long long num;

void parse() {
    int x=0;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='1') {
            v.push_back(x);
            x=0;
        }
        else x++;
    }
    v.push_back(x);
}

int main() {
    cin >> k >> s;
    parse();
    if (k==0) {
        for (int i=0; i<v.size(); i++) {
            num+=(long long)v[i]*(v[i]-1)/2+v[i];
        }
        cout << num << endl;
        return 0;
    }
    for (int i=0; i+k<v.size(); i++) {
        num+=(long long)(v[i]+1)*(v[i+k]+1);
    }
    cout << num << endl;
}