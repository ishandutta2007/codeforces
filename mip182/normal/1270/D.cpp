#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vd vector <double>
#define vll vector <ll>
#define fi first
#define se second
#define si set <int>
#define sll set <ll>
#define spii set <pii>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //#ifdef LOCAL
    //freopen("a.in","r",stdin);
    //#endif
    int n,k;
    cin>>n>>k;
    int  posx,posy,x,y;
    cout<<"? ";
    for (int i=0;i<k;i++)
        cout<<i+1<<" ";
    cout<<endl;
    cin>>posx>>x;
    cout<<"? ";
    for (int i=0;i<k+1;i++) {
        if (i+1!=posx)
        cout << i + 1 << " ";
    }
    cout<<endl;
    cin>>posy>>y;
    if (posy==k+1)
    {
    if (x<y)
    {
    int h=0;
    for (int i=1;i<=k;i++)
    {
        if (i==posx)
            continue;
        cout<<"? ";
        for (int j=1;j<=k;j++)
        {
            if (j!=i)
                cout<<j<<" ";
        }
        cout<<posy<<endl;
        int pos,xx;
        cin>>pos>>xx;
        if (pos==posy)
            h++;
    }
    cout<<"! "<<h+1<<endl;
    return 0;
    } else
    {
        int h=0;
        for (int i=1;i<=k;i++)
        {
            if (i==posx)
                continue;
            cout<<"? ";
            for (int j=1;j<=k;j++)
            {
                if (j!=i)
                    cout<<j<<" ";
            }
            cout<<posy<<endl;
            int pos,xx;
            cin>>pos>>xx;
            if (pos==posx)
                h++;
        }
        cout<<"! "<<h+1<<endl;
        return 0;
    }
    } else
    {
        if (x<y)
        {
            int h=0;
            for (int i=1;i<=k;i++)
            {
                if (i==posx||i==posy)
                    continue;
                cout<<"? ";
                for (int j=1;j<=k;j++)
                {
                    if (j!=i)
                        cout<<j<<" ";
                }
                cout<<k+1<<endl;
                int pos,xx;
                cin>>pos>>xx;
                if (pos==posy)
                    h++;
            }
            cout<<"! "<<h+1<<endl;
            return 0;
        } else
        {
            int h=1;
            for (int i=1;i<=k;i++)
            {
                if (i==posx||i==posy)
                    continue;
                cout<<"? ";
                for (int j=1;j<=k;j++)
                {
                    if (j!=i)
                        cout<<j<<" ";
                }
                cout<<k+1<<endl;
                int pos,xx;
                cin>>pos>>xx;
                if (pos==posx)
                    h++;
            }
            cout<<"! "<<h+1<<endl;
            return 0;
        }
    }




}