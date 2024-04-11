#include<bits/stdc++.h>
using namespace std;

const int nmax=2e4+42;

int n,k,inp[nmax];

int dp[nmax],help[nmax];

int MX[nmax];

int pointer=0;
pair<int,int> lines[nmax];//ax+b

void init()
{
    pointer=0;
}

pair<int,int> meet(pair<int,int> a,pair<int,int> b)
{
    pair<int,int> ret={a.second-b.second,b.first-a.first};

    if(ret.second<0)ret.first=-ret.first,ret.second=-ret.second;

    return ret;
}
bool my_remove(pair<int,int> prv,pair<int,int> to_remove,pair<int,int> cur)
{
    if(prv.first>cur.first)swap(prv,cur);

    pair<int,int> meet_1=meet(prv,to_remove);
    pair<int,int> meet_2=meet(prv,cur);
    /*
    cout<<prv.first<<" "<<prv.second<<" "<<to_remove.first<<" "<<to_remove.second<<" "<<cur.first<<" "<<cur.second<<endl;
    cout<<meet_1.first<<" "<<meet_1.second<<" "<<meet_2.first<<" "<<meet_2.second<<endl;
    */
    return 1LL*meet_1.first*meet_2.second<=1LL*meet_1.second*meet_2.first;
}
void add_line(pair<int,int> cur)//cur.first does not decrease
{
    while(pointer>=1&&lines[pointer].first>=cur.first&&lines[pointer].second>=cur.second)pointer--;

    if(pointer>=1&&lines[pointer].first<=cur.first&&lines[pointer].second<=cur.second)return;

    while(pointer>=2&&my_remove(lines[pointer-1],lines[pointer],cur))pointer--;

    pointer++;
    lines[pointer]=cur;
}

int NOW=1e9;

int eval(int i,int x)
{
    int ret=1LL*x*lines[i].first+lines[i].second;

    NOW=min(NOW,ret);

    return ret;
}
int solve_left(int x)
{
    eval(1,x);
    eval(pointer,x);

    int ok=1,not_ok=pointer;

    while(not_ok-ok>1)
    {
        int av=(ok+not_ok)/2;

        if(eval(av,x)>eval(av+1,x))ok=av;
        else not_ok=av;
    }

    eval(ok,x);
    eval(not_ok,x);
}

int solve_right(int x)
{
    eval(1,x);
    eval(pointer,x);

    int ok=pointer,not_ok=1;

    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;

        if(eval(av,x)<eval(av+1,x))ok=av;
        else not_ok=av;
    }

    eval(ok,x);
    eval(not_ok,x);
}

int query(int x)//x does not decrease
{
    NOW=1e9;

    if(pointer==0)return NOW;

    solve_left(x);
    solve_right(x);

    /*
    int ret=1e9;
    for(int i=1;i<=pointer;i++)
        ret=min(ret,lines[i].first*x+lines[i].second);

    cout<<pointer<<"\n";
    for(int i=1;i<=pointer;i++)
        cout<<lines[i].first<<" "<<lines[i].second<<" "<<lines[i].first*x+lines[i].second<<"\n";
    cout<<"ret= "<<ret<<" NOW= "<<NOW<<"\n";

    assert(ret>=NOW);
    */

    return NOW;
}
void dc(int l,int r)
{
    if(l==r)
    {
        help[l]=min(help[l],dp[l-1]+inp[l]);
        return;
    }

    int av=(l+r)/2;

    dc(l,av);
    dc(av+1,r);

    MX[av]=inp[av];
    for(int i=av-1;i>=l;i--)
        MX[i]=max(MX[i+1],inp[i]);

    MX[av+1]=inp[av+1];
    for(int i=av+2;i<=r;i++)
        MX[i]=max(MX[i-1],inp[i]);

    init();
    int j=l;
    for(int i=r;i>=av+1;i--)
    {
        while(j<=av&&MX[j]>=MX[i])
        {
            add_line({MX[j],dp[j-1]+MX[j]*(-j+1)});
            j++;
        }

        help[i]=min(help[i],query(i));
    }

    init();
    j=av;
    for(int i=av+1;i<=r;i++)
    {
        while(j>=l&&MX[j]<=MX[i])
        {
            add_line({-j,dp[j-1]});
            j--;
        }

        help[i]=min(help[i],query(MX[i])+(i+1)*MX[i]);
    }

    /*
    cout<<"l= "<<l<<" r= "<<r<<endl;
    for(int i=l;i<=r;i++)
        cout<<help[i]<<" ";cout<<endl;

    for(int i=av+1;i<=r;i++)
        for(int j=av;j>=l;j--)
        {
            //cout<<i<<" "<<j<<" "<<help[i]<<" "<<dp[j-1]+(i-j+1)*max(MX[i],MX[j])<<endl;

            //help[i]=min(help[i],dp[j-1]+(i-j+1)*max(MX[i],MX[j]));
            assert(help[i]<=dp[j-1]+(i-j+1)*max(MX[i],MX[j]));
        }
    */
}
void push(int groups)
{
    for(int i=0;i<=n;i++)
        help[i]=1e9;

    dc(1,n);

    for(int i=0;i<=n;i++)
        dp[i]=help[i];

    /*
    cout<<"pushed "<<endl;
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";cout<<endl;
    system("pause");
    */
}

int main()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    /*
    n=20000;
    k=100;
    for(int i=1;i<=n;i++)inp[i]=2e4-i;
    */
    for(int i=1;i<=n;i++)dp[i]=1e9;

    for(int i=1;i<=k;i++)
        push(i);

    printf("%i\n",dp[n]);
    return 0;
}