#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <stdio.h>
using namespace std;

int main()
{
    vector <int> v;
    string s; cin >> s;
    for (int i = 0; i < s.length(); i++){
        if (s[i]!='+') v.push_back(int(s[i])-49);
    }
    sort(v.begin(),v.end());
    for (int i = 0; i < v.size()-1; i++) cout << v[i]+1 << "+";
    cout << v[v.size()-1]+1;
}