#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;
int q[305][305],a[305];
int p[305],pp[305],r[305];
int main(){
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    int n;
    cin>>n;
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            cin>>q[i][j];
    for (int i=0;i<n;i++)
        cin>>a[i];
    for (int i=0;i<n;i++)
    {
        int cp=-1,cpp=-1;
        for (int j=0;j<n;j++)
        {
            if (a[j]<=i+1 && cp==-1)
                cp=a[j];
            else
                if (a[j]<=i+1 && cpp==-1)
                    cpp=a[j];
        }
        p[i]=cp;
        pp[i]=cpp;
    }
    for (int i=0;i<n;i++)
    {
        //cout<<p[i]<<" "<<pp[i]<<endl;
        r[i]=-1;
    }
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            int x=p[j];
            if (x==i+1)
                x=pp[j];
            if (r[i]==-1)
                r[i]=x;
            //cout<<i<<" "<<j<<" "<<x<<endl;
            for (int z=0;z<n;z++)
                if (r[i]==q[i][z])
                {
                    //cout<<z<<"         "<<r[i]<<endl;
                    break;
                }
                else
                    if (q[i][z]==x)
                    {
                        //cout<<z<<" x"<<endl;
                        r[i]=x;
                        break;
                    }
                    
        }
    }
    for (int i=0;i<n;i++)
        cout<<r[i]<<" ";
    return 0;
}