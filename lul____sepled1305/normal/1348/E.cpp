#include<bits/stdc++.h>
using namespace std;
long long n,k,i,j,l,a,b,suma,sumb,mod1,mod2,mod,sum;
pair<long long,long long> bas[1010];
bool visit[1010];
bool visit2[1010];
pair<long long,long long> val[1010];
long long zero = 0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>k;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        bas[i] = {a,b};
        l = min(a,b);
        if(l >= k)
            val[i] = {0,k};
        else if(l==a && a+b>=k)
            val[i] = {max(0LL,k-b),l};
        else if (a+b>=k)
            val[i] = {k-b,min(a,k)};
        suma+=a;
        sumb+=b;
    }
    sum = suma+sumb;
    if(suma%k + sumb%k <k)
        cout<<sum/k;
    else
    {
        visit[0] = true;
        for(i=0;i<n;i++)
        {
            long long pointer1=0, pointer2=0;
            while(true){
                if(visit[pointer1] == true && pointer1<=k)
                {
                    pointer2=pointer1+val[i].first;
                    while(pointer2>=pointer1+val[i].first && pointer2<=pointer1+val[i].second)
                    {
                        visit2[pointer2] = true;
                        pointer2++;
                    }
                }
                else
                {
                    if(pointer1>=k)
                        break;
                }
                pointer1++;
            }
            for(j=0;j<k+10;j++)
            {
                if(visit2[j])
                    visit[j] = true;
            }
            for(j=k;j<2*k+10;j++)
            {
                if(visit2[j])
                    visit[j-k] = true;
            }
        }
        mod1=suma%k;
        mod2=sumb%k;
        mod = mod1+mod2;
        bool plusi =false;
        for(i=k-mod2;i<=mod1;i++)
        {
            if(visit[i])
                plusi = true;
        }
        if(plusi)
            cout<<sum/k;
        else
            cout<<sum/k-1;
    }
}