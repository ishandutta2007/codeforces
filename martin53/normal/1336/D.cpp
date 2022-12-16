#include<bits/stdc++.h>
using namespace std;

const int nmax=1e2+42;

int n,inp[nmax];

pair<int,int> mem[nmax];

int outp[nmax];

int help[nmax];

int order[nmax];

void test()
{
    /*
    cout<<"testing "<<endl;
    for(int i=1;i<=n;i++)
        cout<<outp[i]<<" ";cout<<endl;
    */
    int sum=0;

    for(int i=3;i<=n;i++)
        sum+=outp[i-2]*outp[i-1]*outp[i];

    if(sum!=mem[0].second)return;

    for(int i=1;i<=n;i++)help[i]=outp[i];

    for(int i=1;i<=n;i++)
    {
        int pos=order[i];

        int cur=0;

        if(pos>=3)cur+=help[pos-2]*help[pos-1];
        if(pos>=2&&pos+1<=n)cur+=help[pos-1]*help[pos+1];
        if(pos+2<=n)cur+=help[pos+1]*help[pos+2];

        if(cur!=mem[i].second-mem[i-1].second)return;

        help[pos]++;
    }

    printf("!");
    for(int i=1;i<=n;i++)
        printf(" %i",outp[i]);
    printf("\n");
    exit(0);
}

void gen(int pos)
{
    if(pos==n+1)
    {
        test();
        return;
    }

    if(pos>=4)
    {
        int add=pos-3;
        //check 3 turns ago
        //we added on pos-3
        int diff=mem[add].second-mem[add-1].second;

        if(add>=3)diff=diff-(outp[add-2]+1)*(outp[add-1]+1);
        if(add>=2)diff=diff-(outp[add-1]+1)*outp[add+1];
        diff=diff-(outp[add+1])*(outp[add+2]);

        if(diff)return;
    }
    if(outp[pos]==0)
    {
        for(int i=0;i<=1+(pos==n);i++)
        {
            outp[pos]=i;
            gen(pos+1);
        }
        outp[pos]=0;
    }
    else gen(pos+1);

}

int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)order[i]=i;

    order[n]=1;

    scanf("%i%i",&mem[0].first,&mem[0].second);

    for(int i=1;i<=n;i++)
    {
        int to_add=order[i];

        printf("+ %i\n",to_add);

        cout.flush();

        scanf("%i%i",&mem[i].first,&mem[i].second);

        if(mem[i].first!=mem[i-1].first&&outp[to_add]==0)
        {
            int diff=mem[i].first-mem[i-1].first;

            for(int x=2;true;x++)
                if(x*(x-1)/2==diff)
                {
                    outp[to_add]=x;
                    break;
                }

            if(i==n)outp[1]--;

            //cout<<"! found "<<to_add<<" "<<outp[to_add]<<endl;
        }
    }

    int diff=mem[0].first;
    for(int i=1;i<=n;i++)
        diff=diff-outp[i]*(outp[i]-1)*(outp[i]-2)/6;

    if(diff)
    {
        for(int k=3;true;k++)
            if(k*(k-1)*(k-2)/6==diff)
            {
                outp[n]=k;
                break;
            }
    }

    /*
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> "<<outp[i]<<endl;
    }
    */

    //the info from the first pair is used
    gen(1);

    assert(0==1);

    return 0;
}