#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <functional>
#include <cstring>

#define rep(x,y,z) for (int x=(y),e##x=(z);x<e##x;x++)

using namespace std;

typedef pair<long long,long long> pii;
typedef long long ll;
typedef vector<int> vi;

int main()
{
    int k[5];
    int t[4];
    rep(i,1,4)
    cin>>k[i];
    rep(i,1,4)
       cin>>t[i];
    int n;
    cin>>n;
    k[4]=n+1;
    int *A=new int[n];
    char *S=new char[n];
    memset(S,0,n);
    rep(i,0,n)
        scanf("%d",A+i);
    sort(A,A+n);
    queue<ll> q[4];
    priority_queue<pii,vector<pii>,greater<pii> > ev;
    rep(i,0,n)
        ev.push(pii(A[i],i));
    ll res=0;
    while (!ev.empty())
    {
        int v=ev.top().second;
        ll tm=ev.top().first;
        ev.pop();
        if (S[v]>0)
        {
            k[S[v]]++;
            if (!q[S[v]].empty())
            {
                int v2=q[S[v]].front();
                q[S[v]].pop();
                k[S[v]]--;
                S[v2]++;
                ev.push(pii(tm+t[S[v2]],v2));
            }
        }
        if (k[S[v]+1]>0)
        {
            k[S[v]+1]--;
            S[v]++;
            if (S[v]==4) res=max(res,tm-A[v]);
            else ev.push(pii(tm+t[S[v]],v));
        }
        else
            q[S[v]+1].push(v);

    }
    cout<<res<<endl;
    return 0;
}