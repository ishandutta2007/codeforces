#include <bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mii map <int, int>
#define mll map <ll, ll>
#define pii pair <int, int>
#define pll pair <ll, ll>
#define vi vector <int>
#define vll vector <ll>
#define vpii vector <pair <int,int> >
#define vpll vector <pair <long long,long long> >
#define vvi vector <vector <int> >
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
   // ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        int r,c,k;
        cin>>r>>c>>k;
        vector <string> s(r);
        for (int i=0;i<r;i++)
            cin>>s[i];
        int sum=0;
        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
            {
                if (s[i][j]=='R')
                    sum++;
            }
        }
        int q=sum%k;
        int cnt=sum/k;
        int qwe=0;
        int u=1;
        int cur=0,x=0;
        char d[r][c];
        char y='A';
        while (q>0)
        {
            int chet=0;
            while (chet<cnt+1)
            {
                while ((chet<(cnt+1))&&cur>=0&&cur<c)
                {
                    d[x][cur]=y;
                    if (s[x][cur]=='R')
                        chet++;
                    cur+=u;
                }
                if (cur==c||cur==-1) {
                    if (cur==c)
                        cur = c - 1;
                    else
                        cur = 0;
                    x++;
                    u = -u;
                }
            }
            y++;
            if (y=='Z'+1)
                y='a';
            if (y=='z'+1)
                y='0';
            q--;
            qwe++;
        }
        while (qwe<k)
        {
            int chet=0;
            while (chet<cnt)
            {   //cout<<cur<<" "<<x<<" "<<chet<<'\n';
                while ((chet<cnt)&&cur>=0&&cur<c)
                {
                    d[x][cur]=y;
                    if (s[x][cur]=='R')
                        chet++;
                    //cout<<cur<<" "<<x<<" "<<chet<<'\n';
                    cur+=u;

                }
                if (cur==c||cur==-1) {
                    if (cur==c)
                    cur = c - 1;
                    else
                    cur = 0;
                    x++;
                    u = -u;
                }
            }
            qwe++;
            if (qwe!=k) {
                y++;
                if (y == 'Z' + 1)
                    y = 'a';
                if (y == 'z' + 1)
                    y = '0';
            }
        }
        //cout<<"ahah";
        while (x!=r)
        {
            while (cur>=0&&cur<c)
            {
                d[x][cur]=y;
                cur+=u;
            }
            if (cur==c||cur==-1) {
                if (cur==c)
                    cur = c - 1;
                else
                    cur = 0;
                x++;
                u = -u;
            }
        }
      //  cout<<"haha";
        for (int i=0;i<r;i++)
        {
            for (int j=0;j<c;j++)
                cout<<d[i][j];
            cout<<'\n';
        }
    }
}