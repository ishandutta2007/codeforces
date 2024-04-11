#include<bits/stdc++.h>

using namespace std;

int main()
{
    int s[1001],n,m,a,minn=1000;
    memset(s,0,sizeof(s));
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a;
        s[a]++;
    }
    for(int i=1;i<=n;i++)
        if(s[i]<minn) minn=s[i];
    cout<<minn<<endl;
    return 0;
}