#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42;
int n,output[nmax][nmax];

int arr[4][4]=
{
{8,9,1,13},
{3,12,7,5},
{0,2,4,11},
{6,10,15,14},
};
int main()
{
    scanf("%i",&n);

    int num=0;
    for(int i=1;i<=n;i=i+4)
        for(int j=1;j<=n;j=j+4)
        {
            for(int k=0;k<4;k++)
                for(int l=0;l<4;l++)
                output[i+k][j+l]=arr[k][l]+num;
            num=num+16;
        }
    /*
    for(int i=1;i<=n;i++)
    {
        int x=0;
        for(int j=1;j<=n;j++)
            x=x^output[j][i];
        cout<<i<<" -> "<<x<<endl;
    }
    */
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%i ",output[i][j]);
        printf("\n");
    }

}