#include <iostream>
#include <string>
#include <algorithm>
//#include <math.h>
//#include <vector.h>
//#include <string>
//typedef long long ll; 
using namespace std;

 
int main()
{
    int n,m,k;
    long sum,max=0;
    cin>>n>>m>>k;
    short a[10][100];
    short b[10][100];
    short c[10][100];
    string s;
    for (int i=0;i<n;i++)
    {
        cin>>s;
        for (int j=0;j<m;j++)
            cin>>a[i][j]>>b[i][j]>>c[i][j];
    }
    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (i!=j)
            {
                int w,wi;
                int masa=0;
                sum=0;
                bool used[100];
                for (int i1=0;i1<m;i1++)
                    used[i1]=false;
                
                for (int i1=0;i1<m;i1++)
                {
                    w=-1;wi=-1;
                    for (int j1=0;j1<m;j1++)
                        if (!used[j1] && (b[i][j1]-a[j][j1])>w)
                        {
                            w=b[i][j1]-a[j][j1];
                            wi=j1;
                        }
                    if (w>0)
                    {
                        sum+=min((int) c[j][wi],k-masa)*w;
                        used[wi]=true;
                        masa+=min((int) c[j][wi],k-masa);
                        if (k-masa==0) break;
                    }
                }
                if (sum>max) max=sum;
            }


    cout<<max;
   // system("Pause");
    return 0;

}