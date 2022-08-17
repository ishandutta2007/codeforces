#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

int f(string s)
{
    if (s.length()==0) return 0;
    char last='a';
    ll kol=0;
    for (int i=0;i<s.length();i++)
        if (s[i]!=last)
        {
            last=s[i];
            kol++;
        }
    return kol;
}

int main()
{
    int n, rez, num=0;
    string s,s1;
    cin>>n;
    cin>>s;
    if (n==1) {cout<<1; return 0;}
    rez=f(s);
    for (int i=1;i<s.length();i++)
    {
        if (s[i]==s[i-1]) num++;
        if (num==2) {cout<<rez+2; return 0;}
    }
    if (num==1) {cout<<rez+1; return 0;}
    cout<<rez;
    return 0;
}