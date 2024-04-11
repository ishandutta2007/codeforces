#include<bits/stdc++.h>
using namespace std;
int n,t,u,m,i,l,ss=1e9,k;
int main()
{
    cin>>n>>t;
    for(i=1;i<=n;i++)
    {
        cin>>u>>m;
        if(u>=t){
            l=u;
            if(ss>l) {ss=l; k=i;}
        }
        else {
            if((t-u)%m==0)
            {
                l=u;
            }
            else
            {
                l=u+((t-u)/m)*m+m;
            }
            if(ss>l) {ss=l; k=i;}
        }
        //cout<<l<<" ";
    }
    cout<<k;
}