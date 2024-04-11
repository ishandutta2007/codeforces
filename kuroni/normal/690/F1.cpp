#include <bits/stdc++.h>
using namespace std;
vector <int> a[10001];
int n,st,en,cnt=0;
bool check [10001][10001]={false};
void dfs(int x)
{
    for(int i=1;i<=a[x].size()-1;i++)
    {
        //cout<<x<<" "<<a[x][i]<<endl;
        int temp=a[x][i];
        for(int j=1;j<=a[temp].size()-1;j++)
        {

            if(!check[x][a[temp][j]] && !check[a[temp][j]][x] && x!=a[temp][j])
            {
                cnt++;
                check[x][a[temp][j]]=true;
                check[a[temp][j]][x]=true;
            }
        }
    }
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) a[i].push_back(-1);
    for(int i=1;i<=n-1;i++)
    {
        cin>>st>>en;
        //cout<<st<<" "<<en<<endl;
        a[st].push_back(en);
        //cout<<a[1].size()<<endl;
        a[en].push_back(st);
        check[st][en]=true;
    }
    for(int i=1;i<=n;i++) dfs(i);
    cout<<cnt<<endl;
}