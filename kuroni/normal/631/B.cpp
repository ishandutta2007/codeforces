#include <bits/stdc++.h>
using namespace std;
main()
{
    int row[5000],col[5000],opr[5000],opc[5000],n,m,k,i,a,b,c;
    memset(opr,0,sizeof(opr));
    memset(opc,0,sizeof(opc));
    cin>>n>>m>>k;
    for(int i = 1;i <= k;i++) 
    {
        cin>>a>>b>>c;
        if(a == 1)
        { 
            row[b-1]=c; 
            opr[b-1]=i; 
        }
        else 
        { 
            col[b-1]=c; 
            opc[b-1]=i; 
        }
    }
    for(i=0;i<n;i++) 
    {
        for(int j=0;j<m;j++)
            if(opr[i]>opc[j]) cout<<row[i]<<" ";
            else if(opr[i]<opc[j]) cout<<col[j]<<" ";
            else cout<<0<<" ";
        cout<<endl;
    }
}