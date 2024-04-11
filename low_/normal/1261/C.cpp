#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
// #define int long long
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, m;
vector <vector <char> > V;

vector <vector <int> > ps;

int pSum(int a, int b)
{
    a=min(a, n-1), b=min(b, m-1);
    // cerr<<a<<" "<<b<<"\n";
    if (a<0 || b<0) return 0;
    else return ps[a][b];
}

int prefSum(int a1, int b1, int a2, int b2)
{
    return pSum(a2, b2)-pSum(a1-1, b2)-pSum(a2, b1-1)+pSum(a1-1,b1-1);
}

vector <vector <int> > maxExpand;

bool solveAndMatch(int u)
{
    vector <vector <char> > V2;
    vector <char> temp;
    temp.assign(m, '.');
    V2.assign(n, temp);

    queue <int> qx, qy, qd;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (maxExpand[i][j]>=u)
    {
        qx.push(i);
        qy.push(j);
        qd.push(u);
    }
    pii dx[8]={{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    while (!qx.empty())
    {
        int x=qx.front(), y=qy.front(), d=qd.front();
        qx.pop(), qy.pop(), qd.pop();

        if (V2[x][y]=='X') continue;
        V2[x][y]='X';
        if (d==0) continue;

        for (pii p:dx)
        {
            qx.push(x+p.XX);
            qy.push(y+p.YY);
            qd.push(d-1);
        }
    }

    // cerr<<u<<"\n";
    // for (int i=0; i<n; i++) 
    // {
    //     for (int j=0; j<m; j++) cerr<<V2[i][j];
    //     cerr<<"\n";
    // }

    return (V2==V);
}

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>m;
    vector <char> temp;
    temp.assign(m, '.');
    V.assign(n, temp);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) cin>>V[i][j];

    vector <int> temp2;
    temp2.assign(m, 0);
    ps.assign(n, temp2);

    for (int i=0; i<n; i++) for (int j=0; j<m; j++)
    {
        ps[i][j]=(V[i][j]=='X');
    }

    for (int i=0; i<n; i++) for (int j=1; j<m; j++) ps[i][j]+=ps[i][j-1];
    for (int i=1; i<n; i++) for (int j=0; j<m; j++) ps[i][j]+=ps[i-1][j];
    
    // for (int i=0; i<n; i++) 
    // {
    //     for (int j=0; j<m; j++) cerr<<ps[i][j]<<" ";
    //     cerr<<"\n";
    // }

    temp2.assign(m, -1);
    maxExpand.assign(n, temp2);
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (V[i][j]=='X')
    {
        int l=0, r=min(m, n)/2;
        while (r>l)
        {
            int mid=(l+r)/2+1;

            if (prefSum(i-mid, j-mid, i+mid, j+mid)==(2*mid+1)*(2*mid+1)) l=mid;
            else r=mid-1;
        }

        maxExpand[i][j]=l;
    }
    // for (int i=0; i<n; i++) 
    // {
    //     for (int j=0; j<m; j++) cerr<<maxExpand[i][j]<<" ";
    //     cerr<<"\n";
    // }

    // cerr<<"...\n";
    int l=0, r=min(m, n)/2;
    while (r>l)
    {
        int mid=(l+r)/2+1;
        // cerr<<mid<<"\n";

        bool s=solveAndMatch(mid);
        if (s==0) r=mid-1;
        else l=mid;
    }

    cout<<l<<"\n";

    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<m; j++)
        {
            if (maxExpand[i][j]>=l) cout<<'X';
            else cout<<'.';
        }
        cout<<'\n';
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/