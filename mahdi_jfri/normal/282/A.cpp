#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+20;
int a[maxn];
int main()
{
    int n;
    cin>>n;
    int x=0;
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        if(s.find("++")!=string::npos)
            x++;
        else
            x--;
    }
    cout<<x;
}