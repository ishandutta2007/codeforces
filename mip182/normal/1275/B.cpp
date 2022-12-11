#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define fi first
#define se second
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(),(x).rend()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    int cnt=0;
    if (a==0)
        cnt++;
    if (b==0)
        cnt++;
    if (c==0)
        cnt++;
    if (d==0)
        cnt++;
    if (cnt==3)
    {
        if (a==1)
        {
            cout<<"YES"<<'\n'<<0;
            return 0;
        }
        if (b==1)
        {
            cout<<"YES"<<'\n'<<1;
            return 0;
        }
        if (c==1)
        {
            cout<<"YES"<<'\n'<<2;
            return 0;
        }
        if (d==1)
        {
            cout<<"YES"<<'\n'<<3;
            return 0;
        }
        cout<<"NO";
        return 0;
    }
    ll a1=a,b1=b,c1=c,d1=d;
    vector <ll> ans,ans1,ans2;
    while (a>0&&b>0)
    {
        ans.pb(0);
        ans.pb(1);
        a--,b--;
    }
    if (a>0&&(c!=0||d!=0))
    {
        cout<<"NO";
        return 0;
    }
    if (b==0&&c==0&&d==0)
    {
        if (a==1){
            cout<<"YES";
            cout<<'\n';
            for (int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            cout<<0;
            return 0;
        }
        if (a==0)
        {
            cout<<"YES";
            cout<<'\n';
            for (int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            return 0;
        }
        cout<<"NO";
        return 0;
    }
    while (c>0&&d>0)
    {
        ans2.pb(3);
        ans2.pb(2);
        c--,d--;
    }
    if (a1==0&&b1==0&&c==0)
    {   if (d==1) {
            cout << "YES" << '\n';
            reverse(ans2.begin(), ans2.end());
            cout << 3 << " ";
            for (int i = 0; i < ans2.size(); i++)
                cout << ans2[i] << " ";
            return 0;
        }
        if (d==0)
        {
            cout << "YES" << '\n';
            reverse(ans2.begin(), ans2.end());
            // cout << 3 << " ";
            for (int i = 0; i < ans2.size(); i++)
                cout << ans2[i] << " ";
            return 0;
        }
        cout<<"NO";
        return 0;
    }
    if (d>0&&(a1!=0||b1!=0))
    {
        cout<<"NO";
        return 0;
    }
    reverse(ans2.begin(),ans2.end());
    while (c>0&&b>0)
    {
        ans.pb(2);
        ans.pb(1);
        c--,b--;
    }
    if (b==0&&(c==0||(c==1)))
    {   if (c==1) {
            if (ans2.size()>0){
                ans2.pop_back();
                ans1.pb(2);
                ans1.pb(3);
            }
            else
                ans1.pb(2);
        }
        cout<<"YES"<<'\n';
        for (int i=0;i<ans.size();i++)
            cout<<ans[i]<<" ";
        for (int i=0;i<ans1.size();i++)
            cout<<ans1[i]<<" ";
        for (int i=0;i<ans2.size();i++)
            cout<<ans2[i]<<" ";
        return 0;
    }
    else
    {   ans.clear();ans1.clear();ans2.clear();
        a=a1,b=b1,c=c1,d=d1;
        while (a>0&&b>0)
        {
            ans.pb(1);
            ans.pb(0);
            a--,b--;
        }
        if (a!=0&&(c!=0||d!=0))
        {
            cout<<"NO";
            return 0;
        }
        if (b==0&&c==0&&d==0)
        {
            if (a==1){
                cout<<"YES";
                cout<<'\n';
                for (int i=0;i<ans.size();i++)
                    cout<<ans[i]<<" ";
                cout<<0;
                return 0;
            }
            if (a==0)
            {
                cout<<"YES";
                cout<<'\n';
                for (int i=0;i<ans.size();i++)
                    cout<<ans[i]<<" ";
                return 0;
            }
            cout<<"NO";
            return 0;
        }

        if (b==0&&(c!=0||d!=0))
        {
            cout<<"NO";
            return 0;
        }

        if (b>0)
            ans.pb(1),b--;
        while (c>0&&d>0)
        {
            ans2.pb(3);
            ans2.pb(2);
            c--,d--;
        }
        if (a1==0&&b1==0&&c==0)
        {   if (d==1) {
                cout << "YES" << '\n';
                reverse(ans2.begin(), ans2.end());
                cout << 3 << " ";
                for (int i = 0; i < ans2.size(); i++)
                    cout << ans2[i] << " ";
                return 0;
            }
            if (d==0)
            {
                cout << "YES" << '\n';
                reverse(ans2.begin(), ans2.end());
               // cout << 3 << " ";
                for (int i = 0; i < ans2.size(); i++)
                    cout << ans2[i] << " ";
                return 0;
            }
            cout<<"NO";
            return 0;
        }
        if (d>0&&(a1!=0||b1!=0))
        {
            cout<<"NO";
            return 0;
        }
        reverse(ans2.begin(),ans2.end());
        while (c>0&&b>0)
        {
            ans.pb(2);
            ans.pb(1);
            c--,b--;
        }
        if (b==0&&(c==0||(c==1)))
        {   if (c==1) {
                if (ans2.size()>0){
                    ans2.pop_back();
                    ans1.pb(2);
                    ans1.pb(3);
                }
                else
                    ans1.pb(2);
            }
            cout<<"YES"<<'\n';
            for (int i=0;i<ans.size();i++)
                cout<<ans[i]<<" ";
            for (int i=0;i<ans1.size();i++)
                cout<<ans1[i]<<" ";
            for (int i=0;i<ans2.size();i++)
                cout<<ans2[i]<<" ";
            return 0;
        }

    }
    cout<<"NO";
    return 0;
}