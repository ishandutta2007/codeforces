#include<bits/stdc++.h>
using namespace std;

const int nmax=1e4+42;

int inp[nmax];
int used[nmax];

void solve()
{
    int n,l,r,s;

    scanf("%i%i%i%i",&n,&l,&r,&s);

    int SZ=r-l+1;

    int mini=SZ*(SZ+1)/2;
    int maxi=SZ*(2*n-SZ+1)/2;

    //cout<<"mini= "<<mini<<" maxi= "<<maxi<<endl;

    if(mini<=s&&s<=maxi)
    {
        for(int i=1;i<=n;i++)inp[i]=0,used[i]=0;

        int s_now=0;

        for(int i=l;i<=r;i++)
        {
            inp[i]=i-l+1;
            s_now+=inp[i];
        }

        for(int i=r;i>=l;i--)
        {
            while(s_now<s&&inp[i]<n&&(i==r||inp[i]+1<inp[i+1]))
            {
                s_now++;
                inp[i]++;
            }
        }

        for(int i=l;i<=r;i++)used[inp[i]]=1;

        //cout<<"outp: ";for(int i=1;i<=n;i++)printf("%i ",inp[i]);printf("\n");

        int j=1;

        for(int i=1;i<=n;i++)
            if(inp[i]==0)
            {
                while(used[j])j++;

                inp[i]=j;

                used[j]=1;
            }

        for(int i=1;i<=n;i++)printf("%i ",inp[i]);printf("\n");
    }
    else printf("-1\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}