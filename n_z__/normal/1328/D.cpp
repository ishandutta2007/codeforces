#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n;
        cin>>n;
        int f=0;
        for(int x=1;x<=n;x++)
        cin>>a[x],f+=(a[x]==a[x-1]);
        f+=(a[1]==a[n]);
        if(f==n){cout<<1<<endl;for(int x=1;x<=n;x++)cout<<1<<' ';}
        else{
            if(n%2==0){cout<<2<<endl;for(int x=1;x<=n;x++)cout<<!(x%2)+1<<' ';}
            else if(f==0){cout<<3<<endl;for(int x=1;x<n;x++)cout<<!(x%2)+1<<' ';cout<<3;}
            else{
                cout<<2<<endl;
                bool bo=false;
                for(int x=1;x<=n;x++)
                if(!bo&&a[x]==a[x-1])bo=true,cout<<!((x-1)%2)+1<<' ';
                else cout<<!((x-bo)%2)+1<<' ';
            }
        }
        cout<<endl;
    }
}