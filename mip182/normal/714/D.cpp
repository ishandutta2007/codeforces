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
#define vs vector <string>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define vvpii vector <vector <pii > >
#define forn(i, n) for (int i = 0; i < (n); i++)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define for1(i, n) for (int i = 1; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 1e6+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;
int n;
pair <pii,pii> a={{0,0},{0,0}},b={{0,0},{0,0}};
pair <pii,pii> solve(int x,int y,int x1,int y1)
{
    pair <pii,pii> ans;
    ans.fi={x,y};
    ans.se={x1,y1};
    int l=x+1,r=x1;
    while (l<=r) {
        int mid = (l + r) >> 1;
        cout << "? " << mid << " " << y << " " << x1 << " " << y1 << endl;
        int ok;
        cin >> ok;
        if (ok == 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
            ans.fi.fi = mid;
        }
    }
    l=y+1,r=y1;
    while (l<=r) {
        int mid = (l + r) >> 1;
        cout << "? " << x << " " << mid << " " << x1 << " " << y1 << endl;
        int ok;
        cin >> ok;
        if (ok == 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
            ans.fi.se = mid;
        }
    }
    l=y,r=y1-1;
    while (l<=r) {
        int mid = (l + r) >> 1;
        cout << "? " << x << " " << y << " " << x1 << " " << mid << endl;
        int ok;
        cin >> ok;
        if (ok == 0) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans.se.se = mid;
        }
    }
    l=x,r=x1-1;
    while (l<=r) {
        int mid = (l + r) >> 1;
        cout << "? " << x << " " << y << " " << mid << " " << y1 << endl;
        int ok;
        cin >> ok;
        if (ok == 0) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans.se.fi = mid;
        }
    }
    return ans;
}
pair <pii,pii> solve1(int x,int y,int x1,int y1)
{
    //
    //  cout<<"aahhaha"<<endl;
    pair <pii,pii> ans;
    ans.fi={x,y};
    ans.se={x1,y1};
    int l=x+1,r=x1;
    while (l<=r) {
        int mid = (l + r) >> 1;
        cout << "? " << mid << " " << y << " " << x1 << " " << y1 << endl;
        int ok;
        cin >> ok;
        if (mid<=a.fi.fi&&y<=a.fi.se&&x1>=a.se.fi&&y1>=a.se.se)
            ok--;
        //   cout<<mid<<" "<<ok<<endl;
        if (ok == 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
            ans.fi.fi = mid;
        }
    }
    // cout<<"x "<<ans.fi.fi<<endl;
    l=y+1,r=y1;
    while (l<=r) {
        int mid = (l + r) >> 1;
        cout << "? " << x << " " << mid << " " << x1 << " " << y1 << endl;
        int ok;
        cin >> ok;
        if (x<=a.fi.fi&&mid<=a.fi.se&&x1>=a.se.fi&&y1>=a.se.se)
            ok--;
        if (ok == 0) {
            r = mid - 1;
        } else {
            l = mid + 1;
            ans.fi.se = mid;
        }
    }
    //  cout<<"y "<<ans.fi.fi<<endl;
    l=y,r=y1-1;
    while (l<=r) {
        int mid = (l + r) >> 1;
        cout << "? " << x << " " << y << " " << x1 << " " << mid << endl;
        int ok;
        cin >> ok;
        if (x<=a.fi.fi&&y<=a.fi.se&&x1>=a.se.fi&&mid>=a.se.se)
            ok--;
        if (ok == 0) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans.se.se = mid;
        }
    }
    //  cout<<"x1 "<<ans.se.fi<<endl;
    l=x,r=x1-1;
    while (l<=r) {
        int mid = (l + r) >> 1;
        cout << "? " << x << " " << y << " " << mid << " " << y1 << endl;
        int ok;
        cin >> ok;
        if (x<=a.fi.fi&&y<=a.fi.se&&mid>=a.se.fi&&y1>=a.se.se)
            ok--;
        if (ok == 0) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans.se.fi = mid;
        }
    }
    //   cout<<"y1 "<<ans.se.se<<endl;
    return ans;
}
int main() {
    cin>>n;
    int l=1,r=n;
    int ans=1;
    pair <pii,pii> ha={{0,0},{0,0}};
    while (l<=r)
    {
        int mid=((l+r)>>1);
        cout<<"? "<<mid<<" "<<1<<" "<<n<<" "<<n<<endl;
        int x;
        cin>>x;
        if (x==2)
        {
            ans=mid;
            l=mid+1;
        } else{
            if (x==0)
            {
                r=mid-1;
            } else
            {
                ha={{mid,1},{n,n}};
                break;
            }
        }
    }
    if (ha.fi.se!=0)
    {
        a=solve(ha.fi.fi,ha.fi.se,ha.se.fi,ha.se.se);
        //cout<<a.fi.fi<<" "<<a.fi.se<<" "<<a.se.fi<<" "<<a.se.se<<endl;
        //    cout<<"ahsagfadgfhdghsdh"<<endl;
        b=solve1(1,1,n,n);
    }
    else
    {
        l=1,r=n;
        int anss=1;
        ha={{0,0},{0,0}};
        while (l<=r)
        {
            int mid=((l+r)>>1);
            cout<<"? "<<ans<<" "<<mid<<" "<<n<<" "<<n<<endl;
            int x;
            cin>>x;
            if (x==2)
            {
                anss=mid;
                l=mid+1;
            } else{
                if (x==0)
                {
                    r=mid-1;
                } else
                {
                    ha={{ans,mid},{n,n}};
                    break;
                }
            }
        }
        a=solve(ha.fi.fi,ha.fi.se,ha.se.fi,ha.se.se);
        b=solve1(1,1,n,n);
    }
    cout<<"! "<<a.fi.fi<<" "<<a.fi.se<<" "<<a.se.fi<<" "<<a.se.se<<" "<<b.fi.fi<<" "<<b.fi.se<<" "<<b.se.fi<<" "<<b.se.se<<endl;




}