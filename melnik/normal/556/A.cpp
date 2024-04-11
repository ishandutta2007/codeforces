#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    int n,o=0,l=0;
    cin>>n>>s;
    for (int k=0;k<n;k++)
    if (s[k]=='0') o++; else l++;
    cout<<max(o,l)-min(o,l);
    return 0;
}