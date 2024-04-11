#include<bits/stdc++.h>
using namespace std;

void print(int type)
{
    if(type==1)printf("ACCEPTED\n");
    else printf("REJECTED\n");
    exit(0);
}

const int nmax=42;

int n,k;
vector<int> inp[nmax];

unsigned long long coeff[nmax];

int take(unsigned long long given,int pos)
{
    return (given/coeff[pos])%3;
}

vector<unsigned long long> WORK[nmax];

void direct(unsigned long long given)
{
    int prv=given%3;
    given=given/3;

    for(int i=1;i<n;i++)
    {
        int cur=given%3;
        given=given/3;

        if(prv>cur)print(0);

        prv=cur;
    }
}

bool there[nmax][nmax];

void rec(unsigned long long given,int pos)
{
    //cout<<"rec "<<given<<" "<<pos<<" : ";for(int i=0;i<n;i++)cout<<take(given,i)<<" ";cout<<endl;

    int cnt[3]={0,0,0};

    long long given_new=0,cur_coeff=1;
    for(int i=0;i<n;i++,cur_coeff=cur_coeff*3,given=given/3)
        if(there[pos][i])cnt[given%3]++;
        else given_new+=cur_coeff*(given%3);

    given=given_new;

    //cout<<given<<" "<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<endl;

    //cout<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" given= "<<given<<endl;

    for(int i=cnt[0];i<inp[pos].size();i++)
        given+=coeff[inp[pos][i]];

    //if(pos==10)return;

    //cout<<"gaz "<<cnt[0]<<" "<<cnt[1]<<" "<<cnt[2]<<" given= "<<given<<" : ";for(int i=0;i<n;i++)cout<<take(given,i)<<" ";cout<<endl;

    for(int i=cnt[0];i<=cnt[0]+cnt[2];i++)
    {
        if(i!=cnt[0])given-=coeff[inp[pos][i-1]];

        if(pos+1<=k)WORK[pos+1].push_back(given);
        else direct(given);
    }
}

bool cover(vector<int> a,vector<int> b)
{
    set<int> in_b={};
    for(auto w:b)
        in_b.insert(w);

    for(auto w:a)
        if(in_b.count(w)==0)return 0;

    return 1;
}

int main()
{
    double T=clock();

    coeff[0]=1;
    for(int i=1;i<nmax;i++)coeff[i]=3*coeff[i-1];

    scanf("%i%i",&n,&k);

    set<int> given={};

    for(int i=1;i<=k;i++)
    {
        int SZ;
        scanf("%i",&SZ);
        for(int j=1;j<=SZ;j++)
        {
            int cur;
            scanf("%i",&cur);
            cur--;
            inp[i].push_back(cur);

            given.insert(cur);
        }

        sort(inp[i].begin(),inp[i].end());

        while(i>=2&&cover(inp[i-1],inp[i]))
        {
            inp[i-1]=inp[i];
            inp[i]={};

            i--;
            k--;
        }
    }

    for(int i=1;i<=k;i++)
    {
        for(auto w:inp[i])
            there[i][w]=1;
    }

    if(n==1)print(1);
    if(given.size()!=n)print(0);

    WORK[1].push_back(coeff[n]-1);

    for(int i=1;i<=k;i++)
    {
        //cout<<"i= "<<i<<" "<<WORK[i].size()<<" "<<1.0*(clock()-T)/CLOCKS_PER_SEC<<endl;

        sort(WORK[i].begin(),WORK[i].end());

        //cout<<i<<" -> ";for(auto w:WORK[i])cout<<w<<" ";cout<<endl;

        for(int j=0;j<WORK[i].size();j++)
            if(j==0||WORK[i][j]!=WORK[i][j-1])
            {
                rec(WORK[i][j],i);
                if(i==k)
                {
                    if(1.0*(clock()-T)/CLOCKS_PER_SEC>0.95)print(1);
                }
            }

        WORK[i]={};
        WORK[i].shrink_to_fit();
    }

    print(1);

    return 0;
}