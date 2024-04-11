#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i;
        cin>>n;
        bool found[n];
        for(i=0;i<n;i++)
            found[i] = false;
        for(i=0;i<2*n;i++)
        {
            int b;
            cin>>b;
            b--;
            if(!found[b])
                cout<<b+1<<" ", found[b] = true;
        }
        cout<<"\n";
    }
    return 0;
}