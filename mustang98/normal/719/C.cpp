#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int ll;

int main()
{
    ll n, t;
    string s;
    cin>>n>>t;
    cin>>s;
    if (t==0) {cout<<s; return 0;}
    int f, i = 0;
    while(s[i] != '.') i++;
    for (int j = i+1;j<s.length();j++)
    {
        if((int)s[j]-48 >= 5) {f = j; break;}
        if (j == s.length() - 1) {cout<<s; return 0;}
    }
    while(t)
    {
        if (s[f - 1] == '.')
        {
            for(int l = f-2; l >=0; l--)
            {
                if (s[l] != '9') {s[l]++; for(int j=0;j<f-1;j++)cout<<s[j]; return 0;}
                //s[l] == 9
                if (l != 0) {s[l] = '0'; continue;}
                else {s[l] = '0'; cout<<1; for(int j=0;j<f-1;j++)cout<<s[j]; return 0;}
            }
        }
        s[f - 1]++;
        if (s[f-1] == '5') {f--; t--; continue;}
        else
        {
            for(int k = 0; k < f; k++) cout<<s[k];
            return 0;
        }
    }
    for(int j=0;j<=f;j++)cout<<s[j];
    return 0;
}