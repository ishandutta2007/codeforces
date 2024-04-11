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



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int k;
    cin>>k;
    while (k--)
    {
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        int cnt=0;
        int r=-1,l=-1;
        for(int i=0;i<n;i++)
        {
            if (s[i]==t[i])
                cnt++;
            else
            {
                if (r==-1)
                    r=i;
                else
                    l=i;
            }
        }
      //  cout<<l<<" "<<r<<endl;
        if (n-cnt>2)
            cout<<"No"<<'\n';
        else
        {
            if (l==-1)
            {
                if (cnt==n)
                    cout<<"Yes"<<'\n';
                else
                {
                    cout<<"No"<<'\n';
                }
            } else
            {
                if ((t[r]==t[l]&&s[l]==s[r]))
                    cout<<"Yes"<<'\n';
                else
                    cout<<"No"<<'\n';
            }
        }
    }
}