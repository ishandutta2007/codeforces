#include<bits/stdc++.h>
using namespace std;
const int N = 2e5;
int n,i,a,j;
long long ans,bii;
int bits[N][25];
int total[25];
int powee[25];

void create(int val, int index)
{
    int powe = 2,i;
    for(i=0;i<25;i++)
    {
        bits[index][i] =val%powe - val%(powe/2);
        powe*=2;
    }
}

int main()
{
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>a;
        create(a,i);
    }
    int cur = 1;
    for(i=0;i<25;i++)
    {
        powee[i] = cur;
        cur*=2;
    }
    for(i=0;i<25;i++)
        for(j=0;j<n;j++)
            if(bits[j][i] >0)
                total[i]++;
    for(i=0;i<n;i++)
    {
        int here=0;
        for(j=0;j<25;j++)
        {
            if(total[j]!=0)
            {
                total[j]--;
                here+=powee[j];
            }
        }
        bii = 1LL*here*here;
        ans+=bii;
    }
    cout<<ans;
}