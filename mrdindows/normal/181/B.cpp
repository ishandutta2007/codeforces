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
    int x[3001],y[3001],c=0;
    bool **b=new bool*[7002];
    for (int i=0;i<7002;i++)
    {
        b[i]=new bool[7002];
        for (int j=0;j<7002;j++)
            b[i][j]=false;
    }

    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin>>x[i]>>y[i];
        b[3000+x[i]][3000+y[i]]=true;
    }
    for (int i=1;i<n;i++)
        for (int j=0;j<i;j++)
        {
            if (b[3000+2*x[i]-x[j]][3000+2*y[i]-y[j]]) c++;
            if (b[3000+2*x[j]-x[i]][3000+2*y[j]-y[i]]) c++;
        }
    cout<<c/2;
   // system("Pause");
    return 0;

}