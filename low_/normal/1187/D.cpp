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
#define int long long
#define mn 300005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n;
int A[mn];
int B[mn];
deque <int> pos[mn];

class segmentTree{
private:
    int N;
    int ST[mn*4];
    int pointie=1;

    void UPD(int id, int l, int r, int u, int g)
    {
        if (u<l || u>r) return;
        if (l==r)
        {
            ST[id]=g;
            return;
        }

        int mid=(l+r)/2;
        UPD(id*2, l, mid, u, g);
        UPD(id*2+1, mid+1, r, u, g);
        ST[id]=min(ST[id*2], ST[id*2+1]);
    }

    int GET(int id, int l, int r, int u, int v)
    {
        int ans;
        if (v<l || u>r) return inf;
        if (u<=l && r<=v) ans=ST[id];
        else
        {
            int mid=(l+r)/2;
            ans=min(GET(id*2, l, mid, u, v), GET(id*2+1, mid+1, r, u, v));
        }
        
        
        // cerr<<id<<" "<<l<<" "<<r<<" "<<u<<" "<<v<<" "<<ans<<endl;
        return ans;
    }
public:
    segmentTree()
    {
        for (int i=0; i<mn*4; i++) ST[i]=inf;
    }
    void reset(int nn)
    {
        N=nn;
        for (int i=0; i<=nn*4; i++) ST[i]=inf;
        pointie=1;
    }
    
    void update(int u, int g)
    {
        // cerr<<u<<" "<<g<<endl;
        UPD(1, 1, N, u, g);
    }
    int get(int u, int v)
    {
        // cerr<<u<<" "<<v<<"\n";
        return GET(1, 1, N, u, v);
    }
    int cur()
    {
        return pointie;
    }
    void incCur()
    {
        pointie++;
        while (pointie<=N)
        {
            if (A[pointie]<inf) break;
            pointie++;
        }
    }

};

segmentTree st1;

void refresh(){
    for (int i=1; i<=n; i++) 
    {
        // cerr<<n<<" This test got here\n";
        if (A[i]<inf) pos[A[i]].clear();
        // if (pos[B[i]].em) pos[B[i]].clear();
    }
}

bool doAble()
{
    vector <int> V1={}, V2={};
    for (int i=1; i<=n; i++) V1.push_back(A[i]), V2.push_back(B[i]);
    sort(V1.begin(), V1.end());
    sort(V2.begin(), V2.end());
    return (V1==V2);
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

    int T;
    cin>>T;
    while (T--)
    {
        // cerr<<"----\n";
        refresh();
        // cerr<<"This test got here\n";
        cin>>n;
        for (int i=1; i<=n; i++) cin>>A[i];
        for (int i=1; i<=n; i++) cin>>B[i];
        
        if (!doAble()) 
        {
            cout<<"NO\n";
            continue;
        }
        
        st1.reset(n);
        
        for (int i=1; i<=n; i++) 
        {
            pos[A[i]].push_back(i);
            st1.update(i, A[i]);
        }
        
        bool abl=1;
        for (int i=1; i<=n; i++)
        {
            if (B[i]==A[st1.cur()]) 
            {
                pos[A[st1.cur()]].pop_front();
                st1.incCur();
                continue;
            }
            int x=pos[B[i]].front(); // this x means that we have to push A[x] frontward until it is sorted
            int c=st1.get(st1.cur(), x); //this c is the value of min A[cur, x]
            // cerr<<c<<endl;
            if (c<B[i]) 
            {
                abl=0;
                break;
            }
            pos[B[i]].pop_front();
            A[x]=inf;
            st1.update(x, inf);
        }
        if (!abl) cout<<"NO\n";
        else cout<<"YES\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/