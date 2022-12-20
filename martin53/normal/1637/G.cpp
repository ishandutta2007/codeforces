#include<bits/stdc++.h>
using namespace std;

vector< pair<int,int> > outp={};

map<int,int> seen;

void apply(int x,int y)
{
    //cout<<"apply "<<x<<" "<<y<<endl;

    assert(seen[x]);
    seen[x]--;

    assert(seen[y]);
    seen[y]--;

    seen[x+y]++;
    seen[abs(x-y)]++;

    outp.push_back({x,y});
}

void rec(int n,int coeff)
{
    //cout<<"rec "<<n<<" "<<coeff<<endl;

    if(n<=2)return;

    int pwr=n;

    while((pwr&(pwr-1)))pwr++;

    if(pwr==n)
    {
        rec(n-1,coeff);
        return;
    }

    for(int i=pwr-n;i<pwr/2;i++)
        apply(i*coeff,(pwr-i)*coeff);

    rec(pwr-n-1,coeff);
    rec(pwr/2-(pwr-n),coeff*2);
}
void solve()
{
    int n;

    scanf("%i",&n);

    seen={};
    outp={};

    for(int i=1;i<=n;i++)
        seen[i]=1;

    if(n==2)
    {
        printf("-1\n");
        return;
    }

    rec(n,1);

    /*
    for(auto w:seen)
        if(w.second)cout<<w.first<<" -> "<<w.second<<endl;
    */

    for(auto w:seen)
        if(w.second>=2)
        {
            apply(w.first,w.first);
            break;
        }

    vector< pair<int,int> > mem={};
    for(auto w:seen)
        if(w.second&&w.first>0)mem.push_back(w);

    int MX=mem.back().first;

    for(auto &w:mem)
    {
        while(w.first<MX)
        {
            for(int t=1;t<=w.second;t++)
            {
                apply(0,w.first);
                apply(w.first,w.first);
            }

            w.first=w.first*2;
        }
    }

    apply(0,MX);

    /*
    for(auto w:seen)
        if(w.second)cout<<w.first<<" -> "<<w.second<<endl;
    */

    printf("%i\n",outp.size());

    for(auto w:outp)
        printf("%i %i\n",w.first,w.second);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}