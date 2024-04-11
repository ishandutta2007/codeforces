#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e2+20;
char y;
int main()
{
    int n,m;
    bool x=false;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        {
            cin>>y;
            if(!x)
                if(y!='W' && y!='B' && y!='G')
                    x=true;
        }
    if(x)
        cout<<"#Color";
    else
        cout<<"#Black&White";
}