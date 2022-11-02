#include<bits/stdc++.h>
using namespace std;
long int n,i,d,f,j,k;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%ld%ld%ld%ld",&d,&f,&j,&k);
        if(j%k==f%k)
        {
            if(j-f>0)
            {
                printf("%ld",(j-f)/k);
            }
            else
            {
                printf("%ld",(f-j)/k);
            }
        }
        else if(d%k==1)
        {
            if(j%k==1){
            if((f-1)/k+1+(j-1)/k<=(d-f)/k+1+(d-j)/k)
            {
                cout<<(f-1)/k+1+(j-1)/k;
            }
            else
            {
                cout<<(d-f)/k+1+(d-j)/k;
            }
            }
            else
            {
                cout<<"-1";
            }
        }
        else
        {
            if(j%k==1)
            {
                cout<<(f-1)/k+1+(j-1)/k;
            }
            else if((d-j)%k==0)
            {
                cout<<(d-f)/k+1+(d-j)/k;
            }
            else
            {
                cout<<"-1";
            }
        }
        printf("\n");
    }
    return 0;
}