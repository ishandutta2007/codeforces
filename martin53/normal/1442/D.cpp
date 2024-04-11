#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,k;

int pointer=0;
long long dp[20][nmax];

long long sum[nmax];

long long outp=0;

vector< vector<int> > inp;

long long help[nmax];

void push(int l,int r)
{
    //cout<<"push "<<l<<" "<<r<<" "<<pointer<<endl;

    for(int i=0;i<=k;i++)help[i]=dp[pointer][i];

    for(int i=l;i<=r;i++)
    {
        for(int j=k-inp[i].size();j>=0;j--)
        {
            //cout<<"check "<<i<<" "<<j<<" "<<sum[i]<<endl;

            help[j+inp[i].size()]=max(help[j]+sum[i],help[j+inp[i].size()]);
        }
    }

    pointer++;
    for(int i=0;i<=k;i++)
        dp[pointer][i]=help[i];
    /*
    for(int i=0;i<=k;i++)
        cout<<i<<" -> "<<dp[pointer][i]<<endl;

    cout<<"---"<<endl;
    */
}
void dc(int l,int r)
{
    if(l==r)
    {
        /*
        cout<<"dc "<<l<<" "<<r<<endl;
        for(int i=0;i<=k;i++)
            cout<<dp[pointer][i]<<" ";cout<<endl;
        */
        outp=max(outp,dp[pointer][k]);

        long long sum=0;
        for(int i=0;i<inp[l].size()&&i<k;i++)
        {
            sum+=inp[l][i];

            outp=max(outp,(k-1-i>=0?dp[pointer][k-i-1]:0)+sum);
        }

        return;
    }

    int av=(l+r)/2;

    push(av+1,r);
    dc(l,av);
    pointer--;

    push(l,av);
    dc(av+1,r);
    pointer--;
}
int main()
{
    int q;
    scanf("%i%i",&q,&k);

    for(int i=0;i<q;i++)
    {
        scanf("%i",&n);

        vector<int> cur={};

        for(int j=1;j<=n;j++)
        {
            int now;
            scanf("%i",&now);
            cur.push_back(now);

            sum[i]+=now;
        }

        inp.push_back(cur);
    }

    dc(0,q-1);

    printf("%lld\n",outp);
    return 0;
}