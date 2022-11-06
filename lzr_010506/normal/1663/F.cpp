#include<bits/stdc++.h>
using namespace std;
string s[10];
int main()
{
    s[3]="the";
    s[5]="buffy";
    s[6]="slayer";
    s[7]="vampire";
    string t;
    cin >> t;
    if(t.size() == 4) cout << "none\n";
    else
    {
        for(int i=0;i<t.size();i++)
            putchar((t[i]-'a'+s[t.size()][i]-'a'+52)%26+'a');
    }
    return 0;
}