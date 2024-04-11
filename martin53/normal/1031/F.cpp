#include<bits/stdc++.h>
using namespace std;
const int LIM=1e6+42,nmax=1300;
int divisor[LIM];

void prec()
{
    int p=2;
    while(p*p<LIM)
    {
        for(int j=p*p;j<LIM;j=j+p)divisor[j]=p;
        p++;
        while(divisor[p])p++;
    }

    for(int i=2;i<LIM;i++)
        if(divisor[i]==0)divisor[i]=i;
}
bool cmp(int a,int b)
{
    return a>b;
}
vector<int> factor(int num)
{
    map<int,int> there={};
    while(num!=1)
    {
        there[divisor[num]]++;
        num=num/divisor[num];
    }

    vector<int> ret={};
    for(auto k:there)
        ret.push_back(k.second);
    sort(ret.begin(),ret.end(),cmp);

    return ret;
}
long long MX=1e8;
int primes[12]={2,3,5,7,11,13,17,19,23,29,31,37};

vector< vector<int> > there;
int mem_divs[nmax];
int mem_num[nmax];

map< vector<int>,int> hsh;

int dist_slow[nmax][nmax],output[nmax][nmax];

void test_edge(int i,int j)
{
    dist_slow[i][j]=1e9;
    if(i==j)
    {
        dist_slow[i][j]=0;
        return;
    }

    int g=__gcd(mem_num[i],mem_num[j]);
    int le=mem_num[i]/g,ri=mem_num[j]/g;
    if(le!=1&&ri!=1)return;
    if((le<LIM&&divisor[le]==le&&ri==1)||(le==1&&ri<LIM&&divisor[ri]==ri))
    {
        //cout<<i<<" "<<j<<" 1"<<endl;
        dist_slow[i][j]=1;
        return;
    }
}
void gen(int pos,long long num,int last,vector<int> current)
{
    if(pos>12)
    {
        mem_divs[there.size()]=1;
        for(auto k:current)
            mem_divs[there.size()]*=(k+1);
        mem_num[there.size()]=num;

        hsh[current]=there.size();
        there.push_back(current);

        //cout<<there.size()-1<<" "<<mem_divs[there.size()-1]<<" -> ";for(auto k:current)cout<<k<<" ";cout<<endl;
        return;
    }

    gen(pos+1,num,0,current);

    current.push_back(0);
    for(int i=1;i<=last;i++)
    {
        num=num*primes[pos];
        if(num>MX)return;
        current[pos]++;
        gen(pos+1,num,i,current);
    }
}


int solve()
{
    int a,b;
    scanf("%i%i",&a,&b);

    return output[hsh[factor(a)]][hsh[factor(b)]];
}

int nearest_same[nmax];
int main()
{
    prec();

    gen(0,1,40,{});

    for(int i=0;i<there.size();i++)
        for(int j=0;j<there.size();j++)
        {
            test_edge(i,j);
        }

    int SZ=there.size();
    for(int k=0;k<SZ;k++)
        for(int i=0;i<SZ;i++)
            for(int j=0;j<SZ;j++)
            {
                dist_slow[i][j]=min(dist_slow[i][j],dist_slow[i][k]+dist_slow[k][j]);
            }

    for(int i=0;i<SZ;i++)
        for(int j=0;j<SZ;j++)
            output[i][j]=dist_slow[i][j];

    for(int i=0;i<there.size();i++)
    {
        bool used=0;
        for(int j=0;j<i;j++)
            if(mem_divs[i]==mem_divs[j])used=1;
        if(used)continue;

        vector<int> in={};
        int mini_left=1e9,mini_right=1e9;
        for(int k=0;k<there.size();k++)
            if(mem_divs[i]==mem_divs[k])
                in.push_back(k);

        for(int node=0;node<SZ;node++)
        {
            nearest_same[node]=1e9;
            for(auto current:in)
                nearest_same[node]=min(nearest_same[node],dist_slow[node][current]);
        }

        for(int s=0;s<SZ;s++)
            for(int t=0;t<SZ;t++)
            output[s][t]=min(output[s][t],nearest_same[s]+nearest_same[t]);
    }

    int q;
    scanf("%i",&q);
    for(int i=1;i<=q;i++)
        printf("%i\n",solve());

    return 0;
}