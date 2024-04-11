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
  //  ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    string y=s;
    int j=0;
    while (j+k<n&&s[j]==s[j+k])
        j++;
    if (j+k==n)
    {
        cout<<n<<'\n';
        cout<<s;
        return 0;
    }
    else
    {
     if (s[j]>s[j+k])
     {
     int h=j+k;
     for (int i=j;i<n;i++)
     {
         if (i>=n||i+k>=n)
             break;
         else
         {
             y[i+k]=y[i];
         }
     }
   /* if (j<k)
     {
         for (int f=j+1;f<k;j++)
         {
             int r=0;
             while (r*k+f<n)
                 y[r*k+k]='0',r++;
         }
     } */
     cout<<n<<'\n';
     cout<<y;
     return 0;
     } else
     {
        int f=j%k;
        if (j==j%k)
        {
            bool ok=true;
            for (int t = k - 1; t > f; t--) {
                if (s[t]!='9')
                {
                    ok=false;
                    s[t]=s[t]+1;
                    for (int i=t+1;i<k;i++)
                        s[i]='0';
                    for (int po=0;po<n;po++)
                    {
                        if (po+k<n)
                        {
                            s[po+k]=s[po];
                        }
                        else
                            break;
                    }
                    cout<<n<<'\n';
                    cout<<s;
                    return 0;
                }
        }
            s[f]=s[f]+1;
            for (int i=f+1;i<k;i++)
                s[i]='0';
            for (int i=0;i<n;i++)
            {
                if (i+k<n)
                {
                    s[i+k]=s[i];
                }
                else
                    break;
            }
            cout<<n<<'\n';
            cout<<s;
            return 0;

        }else {
            bool ok=true;
            for (int t = k - 1; t > f; t--) {
            if (s[t]!='9')
            {
            ok=false;
            s[t]=s[t]+1;
            for (int i=t+1;i<k;i++)
                s[i]='0';
                for (int po=0;po<n;po++)
                {
                    if (po+k<n)
                    {
                        s[po+k]=s[po];
                    }
                    else
                        break;
                }
                cout<<n<<'\n';
                cout<<s;
                return 0;
            }
            }
            s[f]=s[f]+1;
            for (int i=f+1;i<k;i++)
                s[i]='0';
            for (int i=0;i<n;i++)
            {
                if (i+k<n)
                {
                    s[i+k]=s[i];
                }
                else
                    break;
            }
            cout<<n<<'\n';
            cout<<s;
            return 0;


        }
     }
    }


}