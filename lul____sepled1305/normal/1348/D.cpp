#include<bits/stdc++.h>
using namespace std;
int t,i;
unsigned int maxi[50];
int po[50];

bool check(int day,int tar)
{
    return maxi[day]>=tar;
}

int b_search(int mini, int ma,int tar)
{
    while(maxi[mini]<tar)
        mini++;
    return mini;
}

int main()
{
    maxi[1] = 2;
    po[1] = 2;
    for(i=2;i<50;i++)
    {
        if(po[i-1]<1e9)
        {
            po[i] = 2*po[i-1];
            maxi[i] = maxi[i-1]+po[i];
        }
        else
        {
            maxi[i] = 2e9;
            po[i] = 1e9;
        }
    }
    cin>>t;
    while(t--)
    {
        int n,ans,j,cur;
        cin>>n;
        ans = b_search(1,50,n-1);
        n-=ans;
        n--;
        cur = 1;
        cout<<ans<<"\n";
        for(j=1;j<=ans;j++)
        {
            int addi = n/(ans-j+1);
            if(addi > cur)
                addi = cur;
            cout<<addi<<" ";
            cur+=addi;
            n-=addi*(ans-j+1);
        }
        cout<<"\n";
    }
}