#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,k;

int inp[nmax];

int been[nmax];

vector<int> seen[nmax];

int jump[17][nmax];

int cnt_letter[17][nmax];
int cnt_question[nmax];

bool check_same(int l,int r,int letter)
{
    return r-l+1==cnt_question[r]-cnt_question[l-1]+cnt_letter[letter][r]-cnt_letter[letter][l-1];
}

bool can(int SZ)
{
    //cout<<"can "<<SZ<<endl;

    for(int i=0;i<=n+1;i++)
    {
        seen[i]={};
        seen[i].shrink_to_fit();
    }

    for(int i=0;i<(1<<k);i++)been[i]=-1;

    for(int i=0;i<k;i++)jump[i][n+1]=-1;

    for(int i=n;i>=1;i--)
        for(int j=0;j<k;j++)
        {
            jump[j][i]=jump[j][i+1];

            if(i+SZ-1<=n)
            {
                if(check_same(i,i+SZ-1,j))
                {
                    jump[j][i]=i+SZ;
                    //cout<<"jump "<<j<<" "<<i<<" -> "<<i+SZ<<endl;
                }
            }
        }

    seen[1].push_back(0);

    for(int i=1;i<=n+1;i++)
    {
        for(auto mask:seen[i])
            if(been[mask]==-1)
            {
                //cout<<mask<<" -> "<<i<<endl;

                been[mask]=1;

                if(mask==(1<<k)-1)return 1;

                for(int b=0;b<k;b++)
                    if((mask&(1<<b))==0)
                    {
                        if(jump[b][i]!=-1)seen[jump[b][i]].push_back(mask+(1<<b));
                    }
            }
    }

    return 0;
}

int main()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)
    {
        char c=getchar();

        while(c!='?'&&('z'<c||c<'a'))c=getchar();

        if(c=='?')inp[i]=-1;
        else inp[i]=c-'a';
    }

    for(int i=1;i<=n;i++)
    {
        cnt_question[i]=cnt_question[i-1]+(inp[i]==-1);

        for(int j=0;j<k;j++)cnt_letter[j][i]=cnt_letter[j][i-1];

        if(inp[i]>=0)cnt_letter[inp[i]][i]++;
    }

    //for(int i=1;i<=n;i++)cout<<inp[i]<<" ";cout<<endl;

    int ok=0,not_ok=n/k+1;

    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;

        if(can(av))ok=av;
        else not_ok=av;
    }

    printf("%i\n",ok);

    return 0;
}