#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>m>>n;
    if(n==1)puts("-1");
    else if(n==2&&m==3||n==3&&m==5)puts("11");
    else{
        int ans=0;
        while(true){
            if(n>=2*m)return cout<<ans+1,0;
            if(n>m)return cout<<ans+3,0;
            if(n==m)return cout<<ans+5,0;
            if(ans==0)m=m-n+2,ans=4;
            else{
                if(n==2||n==3)return cout<<-1,0;
                m=m-n/2+1,ans+=2;
            }
        }
    }
}