#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int INF = 1e9;
const int mx = 2e5;

struct C{
    int n,i;
    C(){};
    C(int n,int i):n(n),i(i){};
    bool operator < (const C &X) const{
        return n>X.n;
    }
};

int cnt,sum,ans,N,M,s,r,tmp;
vector<int> V[mx],S[mx];
priority_queue<C> PQ;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> N >> M;
    for(int i=0; i<N; i++)
    {
        cin >> s >> r;
        V[s].push_back(r);
    }
    for(int i=1; i<=M; i++)
    {
        sort(V[i].begin(),V[i].end(),greater<int>());
        //PQ.push(C(V[i].size(),i));
        tmp = 0;
        for(int j=0; j<V[i].size(); j++)
        {
            tmp += V[i][j];
            S[j+1].push_back(tmp);
        }
    }
    for(int i=1; i<=N; i++)
    {
        sum = 0;
        if(S[i].size()==0) break;
        sort(S[i].begin(),S[i].end(),greater<int>());
        for(int j=0; j<S[i].size(); j++)
        {
            if(S[i][j]<0) break;
            sum += S[i][j];
        }
        ans = max(sum,ans);
    }
    cout << max(ans,0);
}