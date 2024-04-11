#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

char inp[2][nmax];

vector< pair<int,int> > compress(int id)
{
    vector< pair<int,int> > ret={};

    for(int i=1;i<=n;i++)
    {
        int j=i;

        while(j<=n&&inp[id][i]==inp[id][j])j++;

        j--;

        ret.push_back({inp[id][i]-'0',j-i+1});

        i=j;
    }

    return ret;
}

vector<int> take(vector< pair<int,int> > cur)
{
    vector<int> ret={};

    for(int i=0;i<cur.size();i++)
        for(int j=0;j<cur[i].second;j++)
            ret.push_back(i);

    return ret;
}

long long solve()
{
    cin>>n;

    for(int id=0;id<2;id++)
        for(int i=1;i<=n;i++)
            cin>>inp[id][i];

    vector< pair<int,int> > compressed_a=compress(0),compressed_b=compress(1);

    if(compressed_a.size()!=compressed_b.size())return -1;
    if(compressed_a[0].first!=compressed_b[0].first)return -1;

    vector<int> LHS=take(compressed_a),RHS=take(compressed_b);

    /*
    for(auto w:LHS)cout<<w<<"\t";cout<<endl;
    for(auto w:RHS)cout<<w<<"\t";cout<<endl;
    */

    long long output=0;

    for(int i=0;i<n;i++)
        output+=abs(LHS[i]-RHS[i]);

    return output;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<'\n';
    }

    return 0;
}