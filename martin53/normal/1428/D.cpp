#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

set<int> to_match_two,to_match_three;

bool wrong()
{
    printf("-1\n");
    exit(0);
}

int used[nmax];

pair<int/*with*/,int/*which*/> matched[nmax];

vector< pair<int,int> > outp;

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=n;i>=1;i--)
    {
        if(inp[i]==0)continue;

        if(inp[i]==1)
        {
            to_match_two.insert(i);

            to_match_three.insert(i);

            used[i]=1;

            outp.push_back({i,n+1-i});

            continue;
        }

        if(inp[i]==2)
        {
            if(to_match_two.size()==0)wrong();

            int cur=*(to_match_two.begin());

            matched[i]={cur,used[cur]};

            used[cur]++;

            to_match_two.erase(cur);

            to_match_three.erase(cur);

            to_match_three.insert(i);

            outp.push_back({i,n+1-cur});

            used[i]=2;

            continue;
        }

        if(inp[i]==3)
        {
            if(to_match_three.size()==0)wrong();

            int cur=*(to_match_three.begin());

            matched[i]={cur,2};

            used[cur]+=2;

            to_match_two.erase(cur);

            to_match_three.erase(cur);

            to_match_three.insert(i);

            used[i]=2;

            outp.push_back({i,n+1-i});
            outp.push_back({cur,n+1-i});

            continue;
        }
    }
    /*
    for(int i=1;i<=n;i++)
        cout<<i<<" -> "<<matched[i].first<<" "<<matched[i].second<<endl;
    */
    printf("%i\n",outp.size());
    for(auto &w:outp)
    {
        w.second=n+1-w.second;

        swap(w.first,w.second);

        printf("%i %i\n",w.first,w.second);
    }
    return 0;
}