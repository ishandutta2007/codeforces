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
const int MAXN = 5e5+100;
const ll INF = 1e9;
const ll mod1=1e9+7;
const ll mod2=2e9+11;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        string s;
        cin>>s;
        ll sum=0;
        ll check=0;
        ll hehe=0;
        for (int i=0;i<s.size();i++)
        {
            if (s[i]!='0'&&((s[i]-'0')%2==0))
                hehe=1;
            if (s[i]=='0'&&check==1)
                hehe=1;
            if (s[i]=='0')
                check=1;
            sum+=s[i]-'0';
        }
        if (hehe&&check&&sum%3==0)
            cout<<"red";
        else
            cout<<"cyan";
        cout<<'\n';

    }




}