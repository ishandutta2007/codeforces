#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    long long ans=0,c[('z'+1)],i;
    memset (c,0,sizeof(c));
    string s;
    cin >> s;
    for (i=0;i<s.size();i++)
    c[s[i]]++;
    for (i=0;i<('z'+1);i++)
    ans+=(long long)(c[i]*c[i]);
    cout << ans;
}