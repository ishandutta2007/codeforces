#include<bits/stdc++.h>
using namespace std;
const int SZ_MX=11,MX=62,mod=998244353;

int seen[SZ_MX][MX][MX];

int hsh(char a)
{
    if('a'<=a&&a<='z')return a-'a';
    if('A'<=a&&a<='Z')return a-'A'+26;
    return a-'0'+52;
}

int ways_to_fill[MX][MX][MX];

set<string> there={};
void add(string w)
{
    if(there.count(w))return;
    there.insert(w);
    seen[w.size()][hsh(w[0])][hsh(w[w.size()-1])]++;
}
int main()
{
    int n;
    cin>>n;


    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;

        string bck=s;
        reverse(bck.begin(),bck.end());

        add(s);
        add(bck);
    }


    long long output=0;

    for(int SZ=3;SZ<=10;SZ++)
    {
    /*
    for(int i=0;i<MX;i++)
        for(int j=0;j<MX;j++)
            if(seen[SZ][i][j])cout<<SZ<<" "<<i<<" "<<j<<" -> "<<seen[SZ][i][j]<<endl;
    */

    for(int i=0;i<MX;i++)
        for(int j=0;j<MX;j++)
            for(int k=0;k<MX;k++)
            {
                int i_=i,j_=j,k_=k;

                if(i_>j_)swap(i_,j_);
                if(i_>k_)swap(i_,k_);
                if(j_>k_)swap(j_,k_);

                if(i!=i_||j!=j_||k!=k_)
                {
                    ways_to_fill[i][j][k]=ways_to_fill[i_][j_][k_];
                    continue;
                }

                ways_to_fill[i][j][k]=0;
                for(int mid=0;mid<MX;mid++)
                    ways_to_fill[i][j][k]=(ways_to_fill[i][j][k]+1LL*seen[SZ][i][mid]*seen[SZ][j][mid]*seen[SZ][k][mid])%mod;
            }

    for(int i=0;i<MX;i++)
        for(int j=i;j<MX;j++)
            for(int k=j;k<MX;k++)
                for(int l=k;l<MX;l++)
                {
                    long long cur=1LL*ways_to_fill[i][j][k]*ways_to_fill[i][j][l]%mod*ways_to_fill[i][k][l]%mod*ways_to_fill[j][k][l]%mod;

                    int coeff=24;

                    if(i==j&&j==k&&k==l)coeff=1;
                    if(i==j&&j==k&&k!=l)coeff=4;

                    if(i==j&&j!=k&&k==l)coeff=6;
                    if(i==j&&j!=k&&k!=l)coeff=12;

                    if(i!=j&&j==k&&k==l)coeff=4;
                    if(i!=j&&j==k&&k!=l)coeff=12;

                    if(i!=j&&j!=k&&k==l)coeff=12;
                    if(i!=j&&j!=k&&k!=l)coeff=24;

                    output=(output+cur*coeff)%mod;
                }
    }
    printf("%lld\n",output);
    return 0;
}