#include<bits/stdc++.h>
using namespace std;
const int nmax=1e4+42,MX=1e8+42;
int n,m;
int output[nmax];

short seen[MX];

int main()
{
    scanf("%i%i",&n,&m);

    int num=1,current=0;
    for(int i=1;i<=n;i++)
    {
        while(current+seen[num]>m)num++;
        output[i]=num;
        current=current+seen[num];
        num++;

        for(int j=1;j<i;j++)
            seen[output[j]+output[i]]++;
    }

    if(current!=m)
    {
        printf("-1\n");
        return 0;
    }

    for(int i=1;i<=n;i++)printf("%i ",output[i]);
    return 0;
}