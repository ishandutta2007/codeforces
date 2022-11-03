#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
string s;
int main()
{
    cin>>n>>s;
    int num=0;
    for(int i=0;i<n;i++)
        if(s[i]=='8') num++;
    cout<<min(num,n/11);
    return 0;
}