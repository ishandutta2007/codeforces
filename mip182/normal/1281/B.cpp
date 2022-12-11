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
 //   ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        string s,c;
        cin>>s>>c;
        if (s<c)
        {
            cout<<s<<'\n';
            continue;
        }
        map <char,int> m;
        for (int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
      //  for (auto to:m)
       // {
      //      cout<<(int)(to.first)<<" "<<to.second<<'\n';
     //   }
        bool ok=false;
        int i=0;
        bool ko=false;
        while (ok==false&&i<(int)s.size()&&i<(int)c.size())
        {
            char q=c[i];
            for (auto to:m)
            {   if (ok)
                break;
                if (to.first<q&&to.second>0)
                {
                    for (int f=i+1;f<(int)s.size();f++)
                    {
                        if (s[f]==to.first) {
                            swap(s[i], s[f]);
                            break;
                        }
                    }
                    cout<<s<<'\n';
                    ok=true;
                    break;
                }
            }
            if (ok)
                break;
            if (s[i]>c[i])
            {
                if (m[c[i]]>0)
                {
                ok=true;
                bool too=false;
                for (int j=i+1;j<s.size();j++)
                {
                    if (s[j]==c[i])
                    {
                        swap(s[i],s[j]);
                        if (s<c)
                        {
                            cout<<s<<'\n';
                            too=true;
                            break;
                        }
                        swap(s[i],s[j]);
                    }
                }
                if (too==true)
                    break;
                else
                {
                    cout<<"---"<<'\n';
                    break;
                }
                }
                else
                {
                    ok=true;
                    cout<<"---"<<'\n';
                }
                break;
            }
            else
                m[s[i]]--;
            i++;
        }
        if (ok)
            continue;
        cout<<"---"<<'\n';

    }



}