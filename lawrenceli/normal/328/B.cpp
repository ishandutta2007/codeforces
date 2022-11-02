#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num1[10], num2[10];
int minx=1e9;

int main() {
    string t, s;
    cin >> t >> s;
    for (int i=0; i<t.length(); i++) {
        int x=t[i]-'0';
        if (x==5) num1[2]++;
        else if (x==9) num1[6]++;
        else num1[x]++;
    }
    for (int i=0; i<s.length(); i++) {
        int x=s[i]-'0';
        if (x==5) num2[2]++;
        else if (x==9) num2[6]++;
        else num2[x]++;
    }
    for (int i=0; i<10; i++) {
        if (num1[i]==0) continue;
        minx=min(minx, num2[i]/num1[i]);
    }
    cout << minx << endl;
}