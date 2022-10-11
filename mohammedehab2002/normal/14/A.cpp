#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
bool check(vector <string> v,int ind)
{
    int i;
    for (i=0;i<v.size();i++)
    {
        if (v[i][ind]=='*')
        return true;
    }
    return false;
}
int main()
{
    vector <string> v;
    int n,m,i,x,b=0,e,e2;
    bool test=false;
    cin >> n >> m;
    string s[n],c;
    e=m;
    for (i=0;i<m;i++)
    c+='.';
    for (i=0;i<n;i++)
    {
        cin >> s[i];
        if (s[i]!=c)
        test=true;
        if (test)
        v.push_back(s[i]);
    }
    e2=v.size();
    for (i=v.size()-1;i>=0;i--)
    {
        if (v[i]!=c)
        break;
        e2--;
    }
    while (!check(v,b) && b!=e)
    b++;
    while (!check(v,e-1))
    e--;
    for (i=0;i<e2;i++)
    {
        for (x=b;x<e;x++)
        cout << v[i][x];
        cout << endl;
    }
}