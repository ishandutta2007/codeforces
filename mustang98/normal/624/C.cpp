#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

vector<int> r[505];


short int m[502][502];

int s[505];//0 null, 1 - a, 2 - b, 3 - c
char s1[505];

ll n, flag=0;

void err()
{
    if (!flag) cout<<"No";
    flag = 1;
    return;
}

void dfs(int a)
{
    if (flag) return;
    for (int i=0;i<n;i++)
    {
        if (flag) return;
        if (i==a) continue;
        if (s[i]==2) continue;
        if (m[a][i]) // 
        {
            if (s[i]==0) {s[i]=s[a]; dfs(i); continue;}
            if (s[i]==s[a]) continue;
            err();
        }
        else // 
        {
            if (s[i]==s[a]) {err();}
            if (s[i]==0) {s[i]=(s[a]+2)%4; dfs(i); continue;}
        }
    }
}

int main()
{
    ll M,a,b;
    cin>>n>>M;
    for (int i=0;i<M;i++)
    {
        cin>>a>>b;
        a--; b--;
        m[a][b]=1;
        m[b][a]=1;
    }

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            if (m[i][j])
            {
                r[i].push_back(j);
            }
    for (int i=0;i<n;i++)
        if (r[i].size() == n-1) s[i]=2;

    for (int i=0;i<n; i++)
        if (s[i] == 0)
        {
            s[i] = 1;
            dfs(i);
            //cout<<"000";
            break;
        }
    if (flag) return 0;
    for (int i=0;i<n;i++)
    {
        if (s[i]==1) s1[i]='a';
        if (s[i]==2) s1[i]='b';
        if (s[i]==3) s1[i]='c';
        if (s[i]==0) s1[i]='OO';

    }
    cout<<"Yes"<<endl;
    for (int i=0;i<n;i++) cout<<s1[i];
    return 0;
}