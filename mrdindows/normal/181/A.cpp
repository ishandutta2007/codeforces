#include <iostream>
//#include <string>
//#include <math.h>
//#include <vector.h>
//#include <string>
//typedef long long ll; 
using namespace std;

 
int main()
{
    int n,m;
    int x[4],y[4],c=0;
    cin>>n>>m;
    char a[100][100];
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            cin>>a[i][j];
            if (a[i][j]=='*')
            {
                x[c]=i;
                y[c]=j;
                c++;
            }
        }
    if (x[0]==x[1]) cout<<x[2]+1;
    else cout<<x[0]+x[1]-x[2]+1;
    cout<<" ";
    if (y[0]==y[1]) cout<<y[2]+1;
    else cout<<y[0]+y[1]-y[2]+1;
    return 0;

}