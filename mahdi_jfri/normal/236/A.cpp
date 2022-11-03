#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e2+20;
int a[maxn];
int main()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int x=1;
    for(int i=0;i<s.size()-1;i++)
    {
        if(s[i]!=s[i+1])
            x++;
    }
    if(x%2!=0)
        cout<<"IGNORE HIM!";
    else
        cout<<"CHAT WITH HER!";
}