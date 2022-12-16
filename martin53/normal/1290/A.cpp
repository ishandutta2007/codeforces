#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n,me,change,inp[nmax];

int sum[nmax];
bool is[nmax];

bool can(int at_least)
{
    for(int i=1;i<=n;i++)
    {
        is[i]=(inp[i]>=at_least);
        sum[i]=sum[i-1]+is[i];
    }

    for(int force_left=0;force_left<=change;force_left++)
    {
        int least_right=0;
        //there are n-1-force_left people left
        for(int go_left=0;go_left+force_left<me;go_left++)
        {
            int choice_1=force_left+go_left+1;
            int choice_r=n-(me-1-force_left-go_left);

            //cout<<force_left<<" "<<go_left<<" "<<choice_1<<" "<<choice_r<<endl;

            if(is[choice_1]||is[choice_r])continue;

            least_right=max(least_right,min(me-force_left-go_left+1,n-choice_r+1));
            if(force_left+least_right>change)break;
        }

        //cout<<at_least<<" -> "<<force_left<<" "<<least_right<<endl;
        if(force_left+least_right<=change)return 1;
    }
    return 0;
}

int sorted[nmax];
int solve()
{
    scanf("%i%i%i",&n,&me,&change);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);
    for(int i=1;i<=n;i++)sorted[i]=inp[i];
    sort(sorted+1,sorted+n+1);

    change=min(change,me-1);

    int ok=0,not_ok=n+1;
    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;
        if(can(sorted[av]))ok=av;
        else not_ok=av;
    }
    return sorted[ok];
}
int main()
{
    int t;
    scanf("%i",&t);
    for(int i=1;i<=t;i++)
        printf("%i\n",solve());
    return 0;
}