/**Muv Luv power**/
#include<bits/stdc++.h>
const int N = 1e3+10;
using namespace std;
int n,i,on=1,current,prin = 0,step=1,new_prin=1,j,total,best = 0, bestk;
bool slot[N];

int main()
{
    cin>>n;
    for(i=2;i<n;i++)
    {
        int sss = (i-1)*(n/i-1);
        if(n%i!=0)
            sss+=n%i-1;
        if(sss>best)
        {
            best = sss;
            bestk = i;
        }
    }
    int k = bestk;
    if(n>=4)
    {
        cout<<k<<" ";
        for(i=0; i<k; i++)
        {
            cout<<k*prin+1<<" ";
            slot[k*prin+1] = true;
            prin++;
        }
        cout<<"\n";
        fflush(stdout);
        total = k;
        int ss = n%k-1;
        if(ss==-1) ss++;
        while(total<(k-1)*(n/k)+ss)
        {
            cin>>current;
            int ci = 0;
            while(ci<k)
            {
                if(slot[current])
                    total--;
                slot[current] = false;
                current++;
                ci++;
                if(current==n+1)
                    current = 1;
            }
            cout<<"\n";
            int prin = 0;
            cout<<k<<" ";
            for(i=1; i<=k; i++)
            {
                for(j=0; j<=n/k; j++)
                {
                    if(j*k+i<n && slot[j*k+i]==false && prin<k)
                    {
                        slot[j*k+i] = true;
                        prin++;
                        cout<<j*k+i<<" ";
                        total++;
                    }
                }
            }
            cout<<"\n";
            fflush(stdout);
        }
        cin>>current;
        cout<<"0\n";
        fflush(stdout);
    }
    else
    {
        cout<<"0\n";
        fflush(stdout);
    }
}