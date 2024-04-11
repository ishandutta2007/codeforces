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
int n,m,l[200],r[200];
int main(){
   // freopen("input.txt","rt",stdin);
   // freopen("output.txt","wt",stdout);
    int maxi=0;
    char c;
    scanf("%d %d\n",&n,&m);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            cin.get(c);
            if (int(c)==int('W'))
            {
                r[i+1]=j+1;
                if (l[i+1]==0) l[i+1]=j+1;
                maxi=i+1;
            }
        }
        if (i<n-1) cin.get(c);
    }
    if (maxi==0)
    {
        cout<<0;
        return 0;
    }
    //cout<<maxi<<endl;
    int tj=1,re=0;
    for (int i=1;i<=n;i++)
    {
        //cout<<re<<" ";
        if (i<maxi)
        {
            if (r[i+1])
            {
                if (i&1) 
                {
                    re+=max(r[i],r[i+1])-tj;
                    tj=max(r[i],r[i+1]);
                }
                else
                {
                    re+=tj-min(l[i],l[i+1]);
                    tj=min(l[i],l[i+1]);
                }
                re++;
            }
            else
            {
                int h=i+1;
                while (!r[h]) h++;
                if (i&1)
                {
                    re+=r[i]-tj;
                    tj=r[i];
                }
                else
                {
                    re+=tj-l[i];
                    tj=l[i];
                }
                if (h&1)
                {
                    re+=tj-min(tj,l[h]);
                    tj=min(tj,l[h]);
                    
                }
                else
                {
                    re+=max(tj,r[h])-tj;
                    tj=max(tj,r[h]);
                    
                }
                re+=h-i;
                i=h-1;
            }
        }
        else
        {
            if (i&1) 
            {
                re+=r[i]-tj;
            }
            else
            {
                re+=tj-l[i];
            }
            break;
            
        }
        //cout<<re<<endl;
        //cout<<i<<"    "<<re<<"   "<<tj<<endl;
    }
    cout<<re;
    return 0;
}