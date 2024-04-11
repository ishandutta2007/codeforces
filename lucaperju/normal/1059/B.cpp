#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
char v[1007][1007];
int ok[1007][1007];
int main()
{
    int n,m,i,j;
    cin>>n>>m>>ws;
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            cin>>v[i][j];
    for(i=1;i<=n;++i)
        for(j=1;j<=m;++j)
            if(v[i][j]=='#')
            {
                int okc=1;
                for(int ii=i;ii<=i+2;++ii)
                    for(int jj=j;jj<=j+2;++jj)
                        if(ii!=i+1 || jj!=j+1)
                        {
                            if(v[ii][jj]!='#' && !ok[i][j])
                            {
                                cout<<"NO";
                                return 0;
                            }
                            else
                            if(v[ii][jj]!='#')
                                okc=0;
                        }
                if(okc)
                for(int ii=i;ii<=i+2;++ii)
                    for(int jj=j;jj<=j+2;++jj)
                        if(ii!=i+1 || jj!=j+1)
                        {
                            ok[ii][jj]=1;
                        }
            }
    cout<<"YES";
}