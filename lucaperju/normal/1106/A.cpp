#include <bits/stdc++.h>

using namespace std;
char v[505][505];
int main()
{
    long long n,i,j,k,cnt=0,s=0,cur,pz;
    char c='X';
    cin>>n;
    for(i=0;i<n;++i)
        cin>>v[i];
    for(i=1;i<n-1;++i)
        for(j=1;j<n-1;++j)
            if(v[i][j]==c && v[i-1][j-1]==c && v[i-1][j+1]==c && v[i+1][j-1]==c && v[i+1][j+1]==c)
                ++cnt;
    cout<<cnt;
    return 0;
}