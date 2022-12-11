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
#define vvll vector <vll>
#define vsi vector <si>
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
ll l,r,n;
//vector <int> path;
//void solve(ll n,ll left,ll right)
//{
////    cout<<"Func: "<<n<<" "<<left<<" "<<right<<'\n';
//    if (n==1)
//    {
//      //  cout<<l<<" "<<r<<'\n';
//        path.pb(left);
//        reverse(all(path));
//        for (int i=l-1;i<r;i++)
//        {
//            cout<<path[i]<<" ";
//        }
//        return;
//    }
// //   cout<<'\n';
//   // cout<<l<<" "<<2*(n-1)<<'\n';
//   if (l>2*(n-1)) {
//       cout<<n<<" "<<left<<" "<<right<<'\n';
//       l -= 2 * (n - 1), r -= 2 * (n - 1);
//       path.pb(left);
//       path.pb(right);
//       solve(n-2,left+1,right-1);
//       return;
//   }
//   for (int i=1;i<=2*(n-1);i++)
//   {
//       if (l<=i&&i<=r)
//       {
//           if (i%2==1)
//               cout<<left<<" ";
//           else
//               cout<<left+i/2<<" ";
//       }
//   }
//   if (r<=2*n-1)
//       return;
//   else {
//       l=1;
//       r -= 2 * (n - 1);
//       path.pb(left);
//       path.pb(right);
//       solve(n - 2, left + 1, right - 1);
//   }
//
//}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#ifdef LOCAL
    freopen("a.in","r",stdin);
#endif
    int t;
    cin>>t;
    while (t--)
    {
        cin>>n>>l>>r;
        if (l<=2*(n-1))
        {
            for (int i=l;i<=2*(n-1);i++)
            {
                if (i>=l&&i<=r)
                {
                    if (i%2==1)
                        cout<<1<<" ";
                    else
                        cout<<1+i/2<<" ";
                }
            }
            if (r<=(2*(n-1)))
            {
                cout<<'\n';
                continue;
            }
            l=1,r-=2*(n-1);
        }
        else
            l-=2*(n-1),r-=2*(n-1);
        ll cur=n-2;
        ll now=2;
        while (true)
        {
         //   cout<<now<<" "<<cur<<'\n';
            if (now==n)
            {
                cout<<1;
                cout<<'\n';
                break;
            }
            if (l>2*cur)
                now++,l-=2*cur,r-=2*cur,cur--;
            else
            {
                for (int i=1;i<=2*cur;i++)
                {
                    if (i>=l&&r>=i) {
                        if (i & 1)
                            cout << now << " ";
                        else
                            cout << now + i / 2 << " ";
                    }
                }
                if (r<=(2*cur))
                {
                    cout<<'\n';
                    break;
                }
                l=1,r-=2*cur;
                cur--;
                now++;
            }
        }
    }


}