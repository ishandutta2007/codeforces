#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
map<string,int>mp;
string pattern(string a)
{
    string s;
    for(int i=0; i<a.size(); i++)
    {
        s=s + ( ( (a[i] - '0')%2 == 0)?"0":"1");
    }
    return s;
}
string wise(string a,int b)
{
    while(b>a.size())
        a="0"+a;
    return a;
}
int main()
{
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        char s;
        string c;
        cin >> s;
        cin >> c;
        c = wise(pattern(c),18);
        if(s=='+')
        {
            mp[c]++;
        }
        else if(s=='-')
        {
            mp[c]--;
        }
        else
        {
            cout<<mp[c]<<endl;
        }
    }
}