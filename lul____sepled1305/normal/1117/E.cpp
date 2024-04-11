#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
vector<vector<int>> permu;
map<vector<int>,int> gg;
vector<int> ans;
map<int,int> rev;
char wow[N];

void perm(int st, int depth, vector<int> v)
{
    if(depth == 3)
    {
        permu.push_back(v);
        swap(v[1],v[2]);
        permu.push_back(v);
        swap(v[0],v[2]);
        permu.push_back(v);
        swap(v[1],v[2]);
        permu.push_back(v);
        swap(v[0],v[2]);
        permu.push_back(v);
        swap(v[1],v[2]);
        permu.push_back(v);
        return;
    }
    else
    {
        for(int i=st; i<=26;i++)
        {
            v.push_back(i);
            perm(i+1,depth+1,v);
            v.pop_back();
        }
    }
}

int main()
{
    string s[3];
    string o;
    cin>>o;
    vector<int> v;
    perm(1,0,v);
    int n = o.size(),i,j;
    for(j=0;j<3;j++)
    {
        cout<<"? ";
        for(i=0;i<n;i++)
        {
            char c = 'a'+permu[i][j]-1;
            cout<<c;
        }
        cout<<"\n";
        fflush(stdout);
        cin>>s[j];
    }
    for(i=0;i<permu.size();i++)
        gg.insert({permu[i],i});
    for(i=0;i<n;i++)
    {
        vector<int> u;
        for(j=0;j<3;j++)
            u.push_back(s[j][i]-'a'+1);
        ans.push_back(gg[u]);
    }
    for(i=0;i<n;i++)
    {
        wow[ans[i]] = o[i];
    }
    cout<<"! ";
    for(i=0;i<n;i++)
        cout<<wow[i];
    cout<<"\n";
    fflush(stdout);
    return 0;
}