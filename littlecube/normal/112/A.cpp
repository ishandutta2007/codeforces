#include <bits/stdc++.h>
#define ll long long
#define _INFINITY 9223372036854775807
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for (int i = 0; i < s1.length(); i++)
    {
        if (s1[i] < 95)
            s1[i] += 32;
        if (s2[i] < 95)
            s2[i] += 32;
    }
    if(s1 < s2){
        cout << "-1\n";
    }
    if(s1 == s2){
        cout << "0\n";
    }
    if(s1 > s2){
        cout << "1\n";
    }
}