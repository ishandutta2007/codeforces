#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,inp[nmax];

int least[nmax*2];

int outp;

vector<int> seen[nmax];

void solve_small(int big,int small)
{
    for(int i=1;i+1<seen[small].size();i++)
        for(int j=i;j+1<seen[small].size();j++)
        {
            int l=lower_bound(seen[big].begin(),seen[big].end(),seen[small][i])-seen[big].begin();
            int r=upper_bound(seen[big].begin(),seen[big].end(),seen[small][j])-seen[big].begin();

            if(j-i+1<r-l+1)continue;

            for(int l_border=l;l_border>0&&seen[big][l_border]>seen[small][i-1];l_border--)
            {
                int r_border=l_border+j-i;

                if(r_border+1>=seen[big].size())continue;

                int valid_l=seen[big][l_border-1]+1,valid_r=seen[big][r_border+1]-1;

                if(valid_l>seen[small][i]||valid_r<seen[small][j])break;

                //cout<<big<<" "<<small<<" "<<i<<" "<<j<<" "<<l<<" "<<r<<" "<<l_border<<" "<<r_border<<" "<<valid_l<<" "<<valid_r<<endl;

                outp=max(outp,valid_r-valid_l+1);
            }
        }

    //system("pause");

    //cout<<"outp= "<<outp<<endl;
}
void solve_big(int big,int small)
{
    for(int i=0;i<=2*n;i++)
        least[i]=-1;

    least[n]=0;

    int sum=n;
    for(int i=1;i<=n;i++)
    {
        if(inp[i]==big)sum++;
        else if(inp[i]==small)sum--;

        //cout<<big<<" "<<small<<" "<<sum<<" "<<least[sum]<<endl;

        if(least[sum]!=-1)outp=max(outp,i-least[sum]);

        if(least[sum]==-1)least[sum]=i;
    }
}
int main()
{
    scanf("%i",&n);
    //n=4e4;

    int C=pow(n/2.0,1.0/3);

    for(int i=1;i<=n;i++)seen[i].push_back(0);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        /*
        if(i%2==0)inp[i]=i;
        else inp[i]=1;
        */

        seen[inp[i]].push_back(i);
    }

    for(int i=1;i<=n;i++)seen[i].push_back(n+1);

    map<int,int> cnt={};

    for(int i=1;i<=n;i++)cnt[inp[i]]++;

    int maxi=inp[1];

    for(auto k:cnt)
        if(k.second>cnt[maxi])maxi=k.first;

    for(auto k:cnt)
        if(k.first!=maxi)
        {
            if(k.second>C)solve_big(maxi,k.first);
            else solve_small(maxi,k.first);
        }

    printf("%i\n",outp);
    return 0;
}