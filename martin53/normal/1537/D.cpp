#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

bool who[nmax];

int brute(int i)
{
    if(i<=2)return 0;

    if(i%2==1)return 0;

    int cnt_2=0;

    while(i%2==0)
    {
        cnt_2++;
        i=i/2;
    }

    if(i!=1)return 1;

    return cnt_2%2==0;
}
int main()
{
    /*
    for(int i=1;i<nmax;i++)
    {
        for(int j=2;j*j<=i&&who[i]==0;j++)
            if(i%j==0)
            {
                if(who[i-j]==0||who[i-i/j]==0)who[i]=1;
            }

        cout<<i<<" -> "<<who[i]<<endl;

        assert(who[i]==brute(i));
    }
    */

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        int n;
        scanf("%i",&n);

        if(brute(n))printf("Alice\n");
        else printf("Bob\n");
    }

    return 0;
}