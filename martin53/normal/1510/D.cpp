#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,d,inp[nmax];
double add[nmax];

bool eq(double a,double b)
{
    return abs(a-b)<1/1e9;
}

vector<int> outp;

bool solved[nmax][10];
double dp[nmax][10];

double rec(int pos,int dig)
{
    //cout<<"rec "<<pos<<" "<<dig<<endl;

    if(pos>n)
    {
        if(dig==1)return 0;
        return -1e9;
    }

    if(solved[pos][dig])return dp[pos][dig];

    solved[pos][dig]=1;

    dp[pos][dig]=rec(pos+1,dig);

    for(int i=0;i<10;i++)
        if(i*inp[pos]%10==dig)
            dp[pos][dig]=max(dp[pos][dig],rec(pos+1,i)+add[pos]);

    //cout<<pos<<" "<<dig<<" -> "<<dp[pos][dig]<<endl;

    return dp[pos][dig];
}

void print(int pos,int dig)
{
    if(pos>n)return;

    if(eq(rec(pos,dig),rec(pos+1,dig)))
    {
        print(pos+1,dig);
        return;
    }

    for(int i=0;i<10;i++)
        if(i*inp[pos]%10==dig)
        {
            if(eq(rec(pos,dig),rec(pos+1,i)+add[pos]))
            {
                outp.push_back(inp[pos]);
                print(pos+1,i);
                return;
            }
        }
}

int main()
{
    scanf("%i%i",&n,&d);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        add[i]=log(inp[i])+1/1e9;
    }

    if(rec(1,d)<1/1e10)
    {
        printf("-1\n");
        return 0;
    }

    print(1,d);

    printf("%i\n",outp.size());
    for(auto w:outp)printf("%i ",w);
    printf("\n");

    return 0;
}