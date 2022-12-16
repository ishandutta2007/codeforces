#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n,m;

int initial[nmax],cost[nmax];

int gain[nmax+nmax];

unordered_map< long long ,int>  dp;

int outp=0;

int rec(int pos,int lst,int people)
{
    long long hsh=pos;

    hsh=hsh*(n+1);

    hsh=hsh+lst;

    hsh=hsh*(n+1);

    hsh=hsh+people;

    if(pos>n)
    {
        int ret=0;

        while(people>=2)
        {
            lst++;
            people=people/2;

            ret+=people*gain[lst];
        }
        return ret;
    }

    if(dp.count(hsh))return dp[hsh];

    int ret=rec(pos+1,lst,people);//ignore

    //take
    if(lst==initial[pos])
    {
        ret=max(ret,rec(pos+1,lst,people+1)-cost[pos]+gain[initial[pos]]);
    }
    else if(lst<initial[pos])
    {
        int cur_gain=0,cur_lst=lst,cur_people=people;

        while(cur_lst<initial[pos]&&cur_people>1)
        {
            cur_lst++;
            cur_people=cur_people/2;

            cur_gain+=cur_people*gain[cur_lst];
        }

        if(cur_lst!=initial[pos])cur_people=0;

        ret=max(ret,cur_gain+rec(pos+1,initial[pos],cur_people+1)-cost[pos]+gain[initial[pos]]);
    }

    dp[hsh]=ret;

    //cout<<pos<<" "<<lst<<" "<<people<<" -> "<<ret<<endl;

    return ret;
}
int main()
{
    scanf("%i%i",&n,&m);
    for(int i=n;i>=1;i--)scanf("%i",&initial[i]);
    for(int i=n;i>=1;i--)scanf("%i",&cost[i]);

    for(int i=1;i<=n+m;i++)scanf("%i",&gain[i]);

    printf("%i\n",rec(1,0,0));

    return 0;
}