#include<bits/stdc++.h>
#define ll long long
#define fac factoriel
using namespace std;
ll factoriel(int a)
{
    if(a <= 1)
        return 1;
    if(a == 2)
        return 2;
    ll zarb = 1;
    while(a)
    {
        zarb *= a;
        a--;
    }
    return zarb;
}
int main()
{
    string s1 , s2;
    cin >> s1 >> s2;
    int t = 0;
    int pos = 0 , pos2 = 0;
    for(int i = 0; i < s2.size(); i++)
    {
        if(s2[i] == '?')
            t++;
        else if(s2[i] == '+')
            pos2++;
        else
            pos2--;
    }
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1[i] == '+')
            pos++;
        else
            pos--;
    }
    int ezafe = pos2 - pos;
    if(((t - ezafe) & 1) || ezafe > t || (t == 0 && pos2 - pos != 0))
    {
        cout << 0 << ".00000";
        return 0;
    }
    int manfi = (t - ezafe) / 2;
    int mosbat = manfi;
    if(ezafe > 0)
        mosbat += ezafe;
    else
        manfi += ezafe;
    ll possgood = (fac(mosbat + manfi) / fac(mosbat)) / fac(manfi);
    ll poss = 1;
    int i = 0;
    while(i < t)
        poss *= 2,i++;
    double xx;
    xx = (double)(possgood)/(poss);
    printf("%.12f ", xx);
}