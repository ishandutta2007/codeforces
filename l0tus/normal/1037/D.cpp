#include <bits/stdc++.h>
using namespace std;
queue<int> Q;
vector<int> T[200010];
bool v[200010]={0}, c[200010]={0};
int main()
{
    int n,seq[200010];
    cin >> n;
    for(int i=1; i<n; i++)
    {
        int a,b;
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    for(int i=0; i<n; i++) cin >> seq[i];
    int cnt = 0;
    if(seq[0]!=1) cout << "No";
    else
    {
        v[1]=1;
        Q.push(1);
        cnt++;
        while(!Q.empty())
        {
            int x = Q.front(), len = 0;
            Q.pop();
            for(int next : T[x])
            {
                if(v[next]) continue;
                c[next]=1;
                v[next]=1;
                len ++;
            }
            for(int i=0; i<len; i++)
            {
                if(!c[seq[cnt]])
                {
                    cout << "No";
                    return 0;
                }
                c[seq[cnt]]=0;
                Q.push(seq[cnt++]);
            }
        }
        for(int i=1; i<=n; i++)
            {
                if(v[i]) continue;
                cout << "No";
                return 0;
            }
        cout << "Yes";
    }
}