/** Ithea Myse Valgulious **/

#include<bits/stdc++.h>
#define ll long long
using namespace std;
using pii = pair<int,int>;
int T;

struct point
{
    int x,y;

    point(int a,int b)
    {
        x=a,y=b;
    }
};

int dist(point &a, point &b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}

void solve()
{
    int n,k,i,j;
    cin>>n>>k;
    vector<point> v;
    for(i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        v.push_back(point(a,b));
    }
    bool pass = false;
    for(i=0;i<n;i++)
    {
        bool cur_pass = true;
        for(j=0;j<n;j++)
        {
            if(dist(v[i],v[j]) > k)
                cur_pass = false;
        }
        pass = pass | cur_pass;
    }
    if(pass)
        cout<<"1\n";
    else
        cout<<"-1\n";
}

int main()
{
    /**ios_base::sync_with_stdio(false);
    cin.tie(NULL);**/

    cin>>T;
    while(T--)
        solve();
    return 0;
}