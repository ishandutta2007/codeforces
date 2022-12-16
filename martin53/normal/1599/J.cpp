#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42;

int n,inp[nmax];

int outp[nmax];

void print(int type)
{
    if(type==0)
    {
        printf("NO\n");

        exit(0);
    }

    printf("YES\n");
    for(int i=1;i<=n;i++)printf("%i ",outp[i]);
    printf("\n");

    exit(0);
}

bool cmp(int a,int b)
{
    if(a%2!=b%2)return a%2<b%2;
    return a<b;
}

const int BLOCK=28;// C(B,B/2)>B*max(inp)

map<int,int> seen[nmax];

bool SOLVED[nmax];

void dfs(int pos,int sum,int mask,int cnt_bits)
{
    if(pos>n||pos>BLOCK)
    {
        if(seen[cnt_bits].count(sum))
        {
            int other_mask=seen[cnt_bits][sum];

            //cout<<mask<<" "<<other_mask<<endl;

            vector<int> in[2]={};

            for(int i=1;i<pos;i++)
            {
                if((mask&(1<<i)))in[0].push_back(i);
                if((other_mask&(1<<i)))in[1].push_back(i);
            }

            vector<int> order={};
            for(int i=0;i<in[0].size();i++)
            {
                order.push_back(in[0][i]);
                order.push_back(in[1][i]);
            }

            for(int i=1;i<order.size();i++)
                outp[order[i]]=inp[order[i]]-outp[order[i-1]];

            for(auto w:order)SOLVED[w]=1;

            for(int i=1;i<=n;i++)
                if(SOLVED[i]==0)
                    outp[i]=inp[i]-outp[order[0]];

            print(1);
        }
        else seen[cnt_bits][sum]=mask;

        return;
    }

    dfs(pos+1,sum,mask,cnt_bits);
    dfs(pos+1,sum+inp[pos],mask|(1<<pos),cnt_bits+1);
}

int main()
{
    set<int> in={};

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        in.insert(inp[i]);
    }

    if(in.size()<n)
    {
        int pos=1;
        for(auto w:in)
            outp[pos++]=w;

        print(1);
    }

    if(n==2)print(0);
    //n>=3

    sort(inp+1,inp+n+1,cmp);

    if((inp[1]+inp[2]+inp[3])%2==0)
    {
        int sum=(inp[1]+inp[2]+inp[3])/2;

        for(int i=1;i<=3;i++)outp[i]=sum-inp[i];

        for(int i=4;i<=n;i++)outp[i]=inp[i]-outp[1];

        print(1);
    }
    //0 0 1 1 1... or 1 1 1 1...

    if(n==3)print(0);
    //n>=4

    if((inp[2]+inp[3]+inp[4])%2==0)
    {
        int sum=(inp[2]+inp[3]+inp[4])/2;

        for(int i=2;i<=4;i++)outp[i]=sum-inp[i];
        outp[1]=inp[1]-outp[2];

        for(int i=5;i<=n;i++)outp[i]=inp[i]-outp[2];

        print(1);
    }

    //1 1 1 1 1...

    // => |X|=|Y|, sum(X)=sum(Y)
    dfs(1,0,0,0);

    print(0);

    return 0;
}