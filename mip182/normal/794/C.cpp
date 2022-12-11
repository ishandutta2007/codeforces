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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    #ifdef LOCAL
    freopen("a.in","r",stdin);
    #endif
    string ss,tt;
    cin>>ss>>tt;
    int n=ss.size();
    vector <int> s(26),t(26);
    for (int i=0;i<n;i++)
        s[ss[i]-'a']++;
    for (int i=0;i<n;i++)
        t[tt[i]-'a']++;
    string sss="";
    for (int i=0;i<n;i++)
        sss+='?';
    int left=n-1;
    int right=0;
    for (int turn=0;turn<n;turn++)
    {
        if (turn%2==0)
        {
            int cur=0;
            while (s[cur]==0)
                cur++;
         //   cout<<turn<<" "<<cur<<'\n';
            int f=cur+1;
            while (f<26&&t[f]==0)
                f++;
          //  cout<<turn<<" "<<f<<'\n';
            if (f==26)
            {
                int x=(n-turn+1)/2;
                int curr=cur;
                while (x-s[curr]>0)
                    x-=s[curr],curr++;
                cur=curr;
                sss[left]='a'+cur;
                left--;
                s[cur]--;
            }
            else
            {
               // cout<<turn<<" "<<cur<<'\n';
                sss[right]='a'+cur;
                right++;
                s[cur]--;
            }
        }
        else
        {
            int cur=25;
            while (t[cur]==0)
                cur--;
            int f=cur-1;
            while (f>=0&&s[f]==0)
                f--;
            if (f==-1)
            {
                int x=(n-turn+1)/2;
                int curr=cur;
                while (x-t[curr]>0)
                    x-=t[curr],curr--;
                cur=curr;
                sss[left]='a'+cur;
                left--;
                t[cur]--;
            }
            else
            {
                sss[right]='a'+cur;
                right++;
                t[cur]--;
            }
        }
    }
    cout<<sss;






}