#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <deque>
#include <numeric>
#include <string>
#include <random>
typedef long long ll;
#define pb push_back
#define pf push_front
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define sz(x) (int)x.size()


using namespace std;
const ll INFLL = 1e18;
const int MAXN = 3e5;
const ll INF = 1e9;
const ll kek=998244353;


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n;
    cin>>n;
    cin>>s;
    int ans=0;
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='(')
            ans++;
        else
        {
            if (s[i]==')')
                ans--;
            else
                cnt++;
        }
    }
    if (ans>=0)
    {
        if (cnt<ans)
        {
            cout<<":(";
            return 0;
        } else
        {   if ((cnt-ans)%2!=0)
            {
                cout<<":(";
                return 0;
            }
            else{
                int q=(cnt-ans)/2;
            int sum=0;
            bool ok=true;
            for (int i=0;i<n;i++)
            {
                if (s[i]=='(')
                    sum++;
                if (s[i]==')')
                {
                    sum--;
                    if (sum<=0&&i!=(n-1))
                        ok=false;
                }
                if (s[i]=='?')
                {
                    if (q)
                    {
                        s[i]='(';
                        sum++;
                        q--;
                    } else
                    {
                        s[i]=')';
                        sum--;
                        if (sum<=0&&i!=(n-1))
                            ok=false;
                    }
                }
            }
           // cout<<s<<endl;
            if (ok)
                cout<<s;
            else
                cout<<":(";
        }}
    }
    else
    {
        if (cnt<-ans)
        {
            cout<<":(";
            return 0;
        } else
        {   if ((cnt+ans)%2!=0)
            {
                cout<<":(";
                return 0;
            }
            else{
                int q=(cnt+ans)/2-ans;
                int sum=0;
                bool ok=true;
                for (int i=0;i<n;i++)
                {
                    if (s[i]=='(')
                        sum++;
                    if (s[i]==')')
                    {
                        sum--;
                        if (sum<=0&&i!=(n-1))
                            ok=false;
                    }
                    if (s[i]=='?')
                    {
                        if (q)
                        {
                            s[i]='(';
                            sum++;
                            q--;
                        } else
                        {
                            s[i]=')';
                            sum--;
                            if (sum<=0&&i!=(n-1))
                                ok=false;
                        }
                    }
                }
                if (ok)
                    cout<<s;
                else
                    cout<<":(";
            }}
    }
}
/*    int a=-1;
    int sum=0;
    int x;
    int minix=INF;
    for (int i=0;i<n;i++)
    {
       if (s[i]=='(') {
           sum++;
           if (a!=-1)
               minix=min(minix,sum);
       }
       if (s[i]==')') {
           sum--;
           if (a!=-1)
               minix=min(minix,sum);
       }
       if (s[i]=='?')
       {

       }
    }
}

*/