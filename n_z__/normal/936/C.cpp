#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,ans[6001],cnt;
string s,t;
void solvewithapoint(int x)
{
    reverse(s.begin(),s.begin()+n);
    reverse(s.begin()+x,s.begin()+n);
    ans[++cnt]=x;
}
main(){
    cin>>n>>s>>t;
    for(int x=0;x<n;x++)
    {
        int r=0;
        while(s[r]!=t[x]&&r<n)r++;
        if(r>=n-x)return puts("-1"),0;
        if(n-r-1)solvewithapoint(n-r-1);
        solvewithapoint(1);
        if(n-1)solvewithapoint(n-1);
    }
    cout<<cnt<<endl;
    for(int x=1;x<=cnt;x++)
    cout<<ans[x]<<' ';
}