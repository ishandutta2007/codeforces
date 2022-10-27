#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<set>
#include<map>
#include<bitset>
#include<ctime>
#include<queue>
using namespace std;
#define int long long
#define mn 105
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

string CHRS="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

int T, r, c, k;
char B[mn][mn];
char ans[mn][mn];
vector <pair <char, pii> > R;

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>T;
    while (T--)
    {
        cin>>r>>c>>k;
        int cntR=0;
        for (int i=1; i<=r; i++) for (int j=1; j<=c; j++)
        {
            cin>>B[i][j];
            cntR+=(B[i][j]=='R');
        }

        for (int i=1; i<=r; i++) 
        {
            if (i%2==1) 
            {
                for (int j=1; j<=c; j++) R.push_back({B[i][j], {i, j}});
            }
            else
            {
                for (int j=c; j>=1; j--) R.push_back({B[i][j], {i, j}});
            }
        }

        int qq=cntR/k, rr=cntR%k;

        for (int i=0; i<rr; i++)
        {
            int cnt=qq+1;
            while (cnt>0)
            {
                pii P=R.back().second;
                char C=R.back().first;
                R.pop_back();

                ans[P.XX][P.YY]=CHRS[i];
                if (C=='R') cnt--;
            }
        }

        for (int i=rr; i<k; i++)
        {
            int cnt=qq;
            while (cnt>0)
            {
                pii P=R.back().second;
                char C=R.back().first;
                R.pop_back();

                ans[P.XX][P.YY]=CHRS[i];
                if (C=='R') cnt--;
            }
        }

        while (!R.empty())
        {
            pii P=R.back().second;
            R.pop_back();
            ans[P.XX][P.YY]=CHRS[k-1];
        }

        for (int i=1; i<=r; i++) 
        {
            for (int j=1; j<=c; j++) cout<<ans[i][j];
            cout<<"\n";
        }



    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/