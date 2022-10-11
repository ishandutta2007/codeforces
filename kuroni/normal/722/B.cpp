#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;
int main()
{
    map <char,int> chk;
    chk['a'] = chk['e'] = chk['i'] = chk['o'] = chk['u'] = chk['y'] = 1;
    ios_base::sync_with_stdio(0);
    int n, p[100], i, j, tmp;
    string s;
    cin>>n;
    for (i = 0; i < n; i++) cin>>p[i];
    getline(cin,s);
    for (i = 0; i < n; i++)
    {
        tmp = 0;
        getline(cin,s);
        for (j = 0; j < s.length(); j++) tmp += chk[s[j]];
        if (tmp != p[i]) {cout<<"NO"; return 0;}
    }
    cout<<"YES";
    return 0;
}