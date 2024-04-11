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

int main(){
    //freopen("input.txt","rt",stdin);
    //freopen("output.txt","wt",stdout);
    int n,m,M=0;
    cin>>n>>m;
    int k1=n/2;
    int k2=(n+1)/2;
    M=(m/2)*k1+((m+1)/2)*k2;
    for (int i=0;i<=n;i++)
        for (int j=0;j<=m;j++)
        {
            int x;
            if (i%4==0 || i%4==3)
                x=(i+1)/2;
            else
                if (i%4==2)
                {
                    x=(i+2)/2;
                }
                else
                    x=(i+1)/2;
            int y;
            if (j%4==0 || j%4==3)
                y=(j+1)/2;
            else
                if (j%4==2)
                {
                    y=(j+2)/2;
                }
                else
                    y=(j+1)/2;
            int r1,r2;
            r1=x*y+((n-i)/3)*m+((m-j)/3)*i;
            r2=x*y+((n-i)/3)*j+((m-j)/3)*n;
            if (i==0 ||j==0)
            {
                r1=((n-i+2)/3)*m;
                r2=((m-j+2)/3)*n;
            }
            //cout<<i<<" "<<j<<"     "<<r1<<" "<<r2<<endl;
            if (r1>M) M=r1;
            if (r2>M) M=r2; 
        }
        cout<<M;

    return 0;
}