#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42,mod=998244353;
int n,inp[nmax];

int low[nmax];
int total[nmax];

int dp[nmax][2][2];
int query(int what_subtree,int beginning,int ending)
{   //the parent has parity subtree, we want the other
    //cout<<what_subtree<<" "<<beginning<<" "<<ending<<endl;
    if(beginning>ending)return 1;
    if(beginning==ending)return what_subtree!=beginning%2;
    if(dp[ending-beginning][what_subtree][beginning%2]!=-1)return dp[ending-beginning][what_subtree][beginning%2];

    int ret=0;

    for(int i=beginning;i<=ending;i++)
        if(i%2!=what_subtree%2)
    {
        //cout<<"i= "<<i<<" "<<total[ending-beginning+1]<<" =? "<<total[i-beginning]<<" "<<total[ending-i]<<" "<<(ending-beginning)<<endl;
        if(total[ending-beginning+1]==total[i-beginning]+total[ending-i]+(ending-beginning))
        {
            ret=(ret+1LL*query(i%2,beginning,i-1)*query((i+1)%2,i+1,ending))%mod;
        }
    }

    dp[ending-beginning][what_subtree][beginning%2]=ret;
    //cout<<what_subtree<<" "<<beginning<<" "<<ending<<" -> "<<ret<<endl;
    return ret;
}

bool valid[nmax];
int main()
{
    memset(dp,-1,sizeof(dp));

    scanf("%i",&n);

    int l=2;
    while(l<=n+1)
    {
        valid[l-1]=1;
        valid[l]=1;

        if(l%2==0)l=l*2+1;
        else l=l*2;
    }

    printf("%i\n",valid[n]);
    /*
    for(int i=1;i<=1e6;i++)
        if(valid[i])cout<<i<<" ";


    //
    n=1e6;

    for(int i=1;i<=n;i++)
    {
        int h=1;
        while((1<<h)-1<i)h++;
        low[i]=h;

        if(i%2==1)total[i]=2*total[i/2]+(i-1);
        else total[i]=total[i/2]+total[(i-1)/2]+(i-1);

        //cout<<i<<" -> "<<total[i]<<endl;
    }

    for(int i=1;i<=1e6;i++)
    {
        int s=(query(0,1,i)+query(1,1,i))%mod;
        if(s)printf("%i %i\n",i,s);
    }
    */

    return 0;
}