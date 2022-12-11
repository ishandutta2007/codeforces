#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define F first
#define S second
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll kek=998244353;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    string s;
    string t;
    cin>>s>>t;
    vector <int> pi(t.size());
    pi[0]=0;
    for (int i=1;i<t.size();i++)
    {
        int j=pi[i-1];
        while (t[i]!=t[j]&&j)
        j=pi[j-1];
        if (t[i]==t[j])
            j++;
        pi[i]=j;
    }
    int cnt1=0,cnt0=0;
    rep(i,(int)s.size())
    {
       if (s[i]=='1')
           cnt1++;
       else
           cnt0++;
    }
    int a=0,b=0;
    for (int i=0;i<t.size();i++)
    {
        if (t[i]=='1')
            a++;
        else
            b++;
    }
    if (cnt1>=a&&cnt0>=b)
    {
        cout<<t;
        cnt1-=a;
        cnt0-=b;
        int n=0,m=0;
        for (int i=pi[t.size()-1];i<t.size();i++)
        {
            if (t[i]=='1')
                n++;
            else
                m++;
        }
        string g="";
        for (int i=pi[t.size()-1];i<t.size();i++)
        {
            g+=t[i];
        }
        while (cnt1>=n&&cnt0>=m){
            cnt1-=n;
            cnt0-=m;
            cout<<g;
        }
        while (cnt1) {
            cout << 1;
            cnt1--;
        }
        while (cnt0) {
            cout << 0;
            cnt0--;
        }
    }
    else
        cout<<s;
}