#include<bits/stdc++.h>
using namespace std;
int a[10001];
main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int lst=0;
        bool ok=false;
        for(int x=1;x<=n;x++)
        {
            cin>>a[x];
            if(a[x]==1&&a[x-1]==0)ok=true;
        }
        if(a[1]==1){cout<<n+1<<' ';for(int x=1;x<=n;x++)cout<<x<<' ';cout<<endl;}
        else if(a[n]==0){for(int x=1;x<=n;x++)cout<<x<<' ';cout<<n+1<<endl;}
        else if(!ok)puts("-1");
        else{
            bool okk=false;
            for(int x=1;x<=n;x++)
            {
                if(a[x]==1&&a[x-1]==0&&!okk)cout<<n+1<<' ',okk=true;
                cout<<x<<' ';
            } 
            cout<<endl;
        }
    }
}