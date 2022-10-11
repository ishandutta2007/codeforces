#include <iostream>
#include <ios>
#define ll long long
using namespace std;
int spin(char a, char b)
{
    return min(abs((int)a - (int)b), 26 - abs((int)a - (int)b));
}
main()
{
    ios_base::sync_with_stdio(0);
    ll ans = 0, i;
    string s;
    cin>>s;
    s = 'a' + s;
    for (i = 0; i < s.size() - 1; i++) ans += spin(s[i],s[i+1]);
    cout<<ans;
}