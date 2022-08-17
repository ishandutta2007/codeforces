#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
int main()
{
    string s1, s2;
    ll b, e,oo,res=0, k=0, m[200002]={0},kol0;
    cin>>s1;
    cin>>s2;
    for (ll i=0; i<s1.length(); i++)
    {
        if (s1[i]=='0') k++;
        m[i] = k;
    }
    ll nol=0;
    for (ll i=0; i<s1.length(); i++)
    {
        e=i;
        oo=i-(s2.length()-s1.length());
        b=max(nol,oo);
        if (b==0) kol0=m[e];
        else kol0=m[e]-m[b-1];
        if (s2[i] == '1') res += kol0;
        else res += e-b+1-kol0;
    }
    //cout<<res<<endl;
    for (ll i=s1.length();i<=s2.length()-s1.length();i++)
    {
        if (s2[i] == '1') res += m[s1.length()-1];
        else res += s1.length() - m[s1.length()-1];
    }
    //cout<<res<<endl;
    ll LLL;
    for(ll i = max(s2.length()-s1.length()+1,s1.length()); i<s2.length();i++)
    {
        kol0=m[s1.length()-1]-m[i - (s2.length()-s1.length()+1)];
        if (s2[i] == '1') res += kol0;
        else res += s2.length()-i - kol0;
    }
    cout<<res;
    return 0;
}