#include <iostream>
#include <string>
#include <map>
using namespace std;
string stroch(string a)
{
    int n=a.size();
    for (int k=0;k<n;k++)
    if (a[k]>95) a[k]=a[k]-32;
    return a;
}
int main()
{
    int n,k,ma=1;
    map <string,int> i;
    i["POLYCARP"]=1;
    map <string,int>:: iterator w;
    string a,s,d;
    cin>>n;
    for (k=0;k<n;k++)
    {
        cin>>a>>s>>d;
        a=stroch(a);
        d=stroch(d);
        i[a]=i[d]+1;
        if (i[a]>ma) ma=i[a];
    }
    cout<<ma;
    return 0;
}