#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,a,b,c;
        cin >> n >> a >> b >> c;
        int x=0,y=0,z=0;
        string s;
        cin >> s;
        string res;
        int d=0;
        for(int i=0;i<n;i++)
        {
            string add=" ";
            if(s[i]=='R')
            {
                if(b>0)
                {
                    b--;
                    add[0]='P';
                    d++;
                }
            }
            if(s[i]=='P')
            {
                if(c>0)
                {
                    c--;
                    add[0]='S';
                    d++;
                }
            }
            if(s[i]=='S')
            {
                if(a>0)
                {
                    a--;
                    add[0]='R';
                    d++;
                }
            }
            res=res+add;
        }
        if(d>=(n+1)/2)
        {
            db("YES")
            for(int i=0;i<n;i++)
            {
                if(res[i]==' ')
                {
                    if(a)
                    {
                        a--;
                        res[i]='R';
                    }
                    else if(b)
                    {
                        b--;
                        res[i]='P';
                    }
                    else
                    {
                        c--;
                        res[i]='S';
                    }
                }
            }
            db(res)
        }
        else
            db("NO")
    }

    return 0;
}