#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n;
pair<int/*id*/,int/*read*/> inp[nmax];

double MX_score=0;
vector<int> output;

pair<double,int> score[nmax];

bool cmp(pair<double,int> a,pair<double,int> b)
{
    return a.first>b.first;
}

void solve(int to_use)
{
    memset(score,0,sizeof(score));

    for(int i=1;i<nmax;i++)score[i]={0,i};

    for(int i=1;i<=n;i++)
        if(inp[i].second>to_use)score[inp[i].first].first+=1;
        else score[inp[i].first].first+=1.0*inp[i].second/to_use;

    sort(score+1,score+nmax,cmp);

    double score_now=0;
    for(int i=1;i<=to_use;i++)score_now+=score[i].first;

    if(score_now>MX_score)
    {
        MX_score=score_now;

        output={};

        for(int i=1;i<=to_use;i++)output.push_back(score[i].second);
    }

    //cout<<to_use<<" -> "<<score_now<<endl;
}

pair<long long/*sum_coeff*/,int/*id*/> seen[nmax];

bool cmp_big(pair<long long/*sum_coeff*/,int/*id*/> a,pair<long long/*sum_coeff*/,int/*id*/> b)
{
    return a.first>b.first;
}
void solve_big()
{
    for(int i=1;i<nmax;i++)seen[i]={0,i};

    for(int i=1;i<=n;i++)seen[inp[i].first].first+=inp[i].second;

    sort(seen+1,seen+nmax,cmp_big);

    long long SUM=0;

    int flip_with=0;

    for(int i=1;i<nmax;i++)
    {
        SUM+=seen[i].first;

        if(i>20)
        {
            double score_now=1.0*SUM/i;

            if(score_now>MX_score)
            {
                MX_score=score_now;

                flip_with=i;
            }
        }
    }

    if(flip_with)
    {
        output={};

        for(int i=1;i<=flip_with;i++)
            output.push_back(seen[i].second);
    }

    //cout<<MX_score<<endl;
}

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i%i",&inp[i].first,&inp[i].second);

    for(int k=1;k<=20;k++)
    {
        solve(k);
    }

    //cout<<MX_score<<endl;

    solve_big();

    printf("%i\n",output.size());
    for(auto w:output)printf("%i ",w);
    printf("\n");

    return 0;
}