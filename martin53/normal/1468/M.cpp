#include<bits/stdc++.h>
using namespace std;

const int BIG=100,nmax=2e5+42;
const long long base=1e9+42;

vector< pair<int/*value*/,int/*id*/> > active[nmax];

vector< int/*value*/ > seen[nmax];

int n;

void compress()
{
    vector< int > nums={};

    for(int i=1;i<=n;i++)
    {
        for(auto w:seen[i])
            nums.push_back(w);
    }

    sort(nums.begin(),nums.end());

    for(int i=1;i<=n;i++)
    {
        vector<int> seen_new={};

        for(auto w:seen[i])
        {
            int pos=lower_bound(nums.begin(),nums.end(),w)-nums.begin();

            seen_new.push_back(pos);
        }

        seen[i]=seen_new;

        //for(auto w:seen[i])cout<<w<<" ";cout<<endl;
    }

}

int cnt[nmax];

void push(int id,int coeff)
{
    for(auto w:seen[id])
        cnt[w]+=coeff;
}
void solve()
{
    scanf("%i",&n);
    //n=200;

    int pointer=0;

    for(int i=1;i<=n;i++)
    {
        int SZ;

        scanf("%i",&SZ);

        pointer+=SZ;

        //SZ=1000;

        seen[i]={};

        for(int j=1;j<=SZ;j++)
        {
            int num;

            scanf("%i",&num);

            seen[i].push_back(num);
        }

        sort(seen[i].begin(),seen[i].end());
    }

    for(int i=0;i<=pointer;i++)active[i]={};

    compress();

    for(int i=1;i<=n;i++)
    {
        if(seen[i].size()<BIG)
        {
            for(auto p:seen[i])
                for(auto q:seen[i])
                    if(p<q)
                    {
                        active[p].push_back({q,i});
                    }
        }
        else
        {
            push(i,1);

            for(int j=1;j<=n;j++)
                if(j!=i)
            {
                int cur=0;

                for(auto w:seen[j])
                {
                    if(cnt[w])cur++;

                    //cout<<"test "<<w<<" -> "<<seen[i].count(w)<<endl;
                }

                //cout<<i<<" "<<j<<" -> "<<cur<<endl;

                if(cur>=2)
                {
                    printf("%i %i\n",j,i);

                    push(i,-1);

                    return;
                }
            }

            push(i,-1);
        }

    }

    for(int i=0;i<=pointer;i++)
    {
        sort(active[i].begin(),active[i].end());

        for(int j=1;j<active[i].size();j++)
            if(active[i][j-1].first==active[i][j].first)
            {
                printf("%i %i\n",active[i][j-1].second,active[i][j].second);
                return;
            }
    }

    printf("-1\n");
}

int main()
{
    int t;

    scanf("%i",&t);
    //t=1;

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}