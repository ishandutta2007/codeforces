#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,q;

int cnt[nmax][3][3];//position, letter, mod 3

int cnt_help[3][3];

int query()
{
    int l,r;

    cin>>l>>r;

    for(int j=0;j<3;j++)
        for(int k=0;k<3;k++)
            cnt_help[j][k]=cnt[r][j][k]-cnt[l-1][j][k];

    int save=0;

    save=max(save,cnt_help[0][0]+cnt_help[1][1]+cnt_help[2][2]);
    save=max(save,cnt_help[0][0]+cnt_help[1][2]+cnt_help[2][1]);
    save=max(save,cnt_help[0][1]+cnt_help[1][0]+cnt_help[2][2]);
    save=max(save,cnt_help[0][1]+cnt_help[1][2]+cnt_help[2][0]);
    save=max(save,cnt_help[0][2]+cnt_help[1][1]+cnt_help[2][0]);
    save=max(save,cnt_help[0][2]+cnt_help[1][0]+cnt_help[2][1]);

    return r-l+1-save;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();

    cin>>n>>q;

    for(int i=1;i<=n;i++)
    {
        char c;
        cin>>c;

        int val=c-'a';

        for(int j=0;j<3;j++)
            for(int k=0;k<3;k++)
                cnt[i][j][k]=cnt[i-1][j][k];

        cnt[i][val][i%3]++;
    }

    for(int i=1;i<=q;i++)
        cout<<query()<<"\n";

    return 0;
}