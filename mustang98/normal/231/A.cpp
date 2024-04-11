#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <string>
#include <stdio.h>
using namespace std;
//+-32
int main()
{
   /* string s1, s2;
    cin >> s1 >> s2;
    int i = 0;
    while (i < min(s1.length(),s2.length())){
        if (s1[i] >= 'A') s1[i]= char(int(s1[i])+32);
        if (s2[i] >= 'A') s2[i]= char(int(s2[i])+32);
        cout << s1[i];
        if (s1[i] > s2[i]) {cout << 1; return 0;}
        if (s1[i] < s2[i]) {cout << -1; return 0;}
        if (s1[i] == s2[i]) {i++;}
    }
    cout << 0;*/
    int n,m,count = 0;
    cin >> n;

    for (int i = 0 ; i < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        if (a+b+c >= 2) count++;
    }
    cout << count;
}