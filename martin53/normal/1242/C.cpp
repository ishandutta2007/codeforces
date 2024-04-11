#include<bits/stdc++.h>
using namespace std;
const int nmax=5e3+42,kmax=16,MX=(1<<15)+42;
int k;
int inp[kmax][nmax];

long long sum[kmax];

void no()
{
    printf("No\n");
    exit(0);
}

map<long long,int> seen;

bool can[MX],been[MX];

bool tested[MX];

vector<int> used_now;

pair<int/*number*/,int/*to*/> output[nmax];

long long want;

void print()
{
    //for(auto p:used_now)cout<<p<<" ";cout<<endl;

    for(auto match:used_now)
    {
        for(int i=1;i<=k;i++)
        {

        for(int j=1;j<=inp[i][0];j++)
        {
            for(int p=1;p<=k;p++)been[p]=0;

            long long current=inp[i][j],box=i;

            while(been[box]==0)
            {
                been[box]=1;

                long long look=want-(sum[box]-current);

                if(seen.count(look)==0)
                {
                    box=-1;
                    break;
                }

                box=seen[look];
                current=look;
            }

            if(box==i&&current==inp[i][j])
            {
                int num=0;
                for(int j=1;j<=k;j++)
                    if(been[j])num=num+(1<<(j-1));

                //cout<<"num= "<<num<<" want= "<<match<<endl;

                if(num!=match)continue;

                for(int p=1;p<=k;p++)been[p]=0;

                long long current=inp[i][j],box=i;

                while(been[box]==0)
                {
                been[box]=1;

                long long look=want-(sum[box]-current);

                if(seen.count(look)==0)
                {
                    box=-1;
                    break;
                }

                //cout<<box<<" "<<current<<" "<<seen[look]<<endl;

                output[box].first=current;

                output[seen[look]].second=box;

                box=seen[look];
                current=look;
                }

                i=k;
                j=5e3+42;

            }
        }

        }
    }

    printf("Yes\n");
    for(int i=1;i<=k;i++)
        printf("%i %i\n",output[i].first,output[i].second);
    exit(0);
}

bool solve(int state)
{
    if(state==0)
    {
        print();
    }
    if(tested[state])return 0;
    tested[state]=1;

    for(int submask = state; submask; submask = (submask - 1) & state)
        if(can[submask])
        {
            used_now.push_back(submask);
            if(solve(state^submask))return 1;
            used_now.pop_back();
        }
    return 0;
}
int main()
{
    memset(tested,0,sizeof(tested));

    scanf("%i",&k);

    for(int i=1;i<=k;i++)
    {
        scanf("%i",&inp[i][0]);
        for(int j=1;j<=inp[i][0];j++)
        {
            scanf("%i",&inp[i][j]);
            want=want+inp[i][j];
            sum[i]+=inp[i][j];
            seen[inp[i][j]]=i;
        }
    }

    //for(int i=1;i<=k;i++)cout<<sum[i]<<" ";cout<<endl;

    if(want%k!=0)no();

    want=want/k;

    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=inp[i][0];j++)
        {
            for(int p=1;p<=k;p++)been[p]=0;

            long long current=inp[i][j],box=i;

            while(been[box]==0)
            {
                been[box]=1;

                long long look=want-(sum[box]-current);

                if(seen.count(look)==0)
                {
                    box=-1;
                    break;
                }

                box=seen[look];
                current=look;
            }

            if(box==i&&current==inp[i][j])
            {
                int num=0;
                for(int j=1;j<=k;j++)
                    if(been[j])num=num+(1<<(j-1));
                can[num]=1;
                /*
                cout<<"num= "<<num<<endl;
                cout<<i<<" "<<inp[i][j]<<endl;
                */
            }
        }
    }
    /*
    for(int i=0;i<(1<<k);i++)
        if(can[i])cout<<i<<" -> "<<can[i]<<endl;
    */

    if(solve((1<<k)-1)==0)no();
    return 0;
}