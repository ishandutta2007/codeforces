#include<iostream>
#include<cstdio>
using namespace std;
int t;
int n;string s;
inline bool check()
{
    for(int i=0;i<n;i++)
        if(abs(s[i]-s[n-i-1])>2||abs(s[i]-s[n-i-1])==1) return 0;
    return 1;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        if(check()) puts("YES");
        else puts("NO");
    }
    return 0;
}