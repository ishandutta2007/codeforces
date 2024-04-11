#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];
int hsh[nmax];
int arr[nmax];
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        hsh[inp[i]]=i;
    }

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&arr[i]);
        arr[i]=hsh[arr[i]];
    }


    int output=n;
    int least=n+1;

    for(int i=n;i>=1;i--)
    {
        if(arr[i]<least)output--,least=arr[i];
    }
    /*
    for(int i=1;i<=n;i++)
        printf("%i ",arr[i]);
    */
    printf("%i\n",output);

    return 0;
}