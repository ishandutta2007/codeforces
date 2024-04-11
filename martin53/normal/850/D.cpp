#include<bits/stdc++.h>
using namespace std;
const int nmax=32;
int n,arr[nmax];

vector<int> output,current;

bool been[2*nmax][2*nmax*nmax][nmax];

void dfs(int people,int sum,int position)
{
    if(position>n)
    {
        if(people*(people-1)/2==sum)
        {
            if(output.size()==0)output=current;
            else if(output.size()>current.size())output=current;
        }
        return;
    }
    if(been[people][sum][position])return;
    been[people][sum][position]=1;

    int take_now=1;
    for(;take_now*arr[position]+sum>=(people+take_now)*(people+take_now-1)/2;take_now++)
    {
        current.push_back(arr[position]);
        dfs(people+take_now,take_now*arr[position]+sum,position+1);
    }

    for(int i=1;i<take_now;i++)
    {
        current.pop_back();
    }
}

pair<int/*person*/,int/*degree*/> work[2*nmax];
bool cmp(pair<int/*person*/,int/*degree*/> a,pair<int/*person*/,int/*degree*/> b)
{
    return a.second<b.second;
}
int out[2*nmax][2*nmax];
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&arr[i]);
    sort(arr+1,arr+n+1);

    dfs(0,0,1);

    if(output.size()==0)
    {
        printf("=(");
        return 0;
    }

    printf("%i\n",output.size());
    for(int i=1;i<=output.size();i++)work[i]={i,output[i-1]};

    for(int steps=output.size();steps>=1;steps--)
    {
        sort(work+1,work+steps+1,cmp);

        assert(work[steps].second<steps);
        int who=work[steps].first;

        for(int j=1;j<=work[steps].second;j++)
            out[who][work[j].first]=1;

        for(int j=work[steps].second+1;j<steps;j++)
        {
            assert(work[j].second);
            work[j].second--;
            out[work[j].first][who]=1;
        }
    }

    for(int i=1;i<=output.size();i++)
    {
        for(int j=1;j<=output.size();j++)printf("%i",out[i][j]);
        printf("\n");
    }
    return 0;
}