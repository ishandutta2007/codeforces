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
#define mn 2005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n, m;
char board[mn][mn], redraw[mn][mn];

vector <pii> pos[27];
pair <pii, pii> Ans[27];

void refresh()
{
    for (int i=0; i<27; i++) pos[i].clear(), Ans[i]={{0, 0}, {0, 0}};
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) board[i][j]=redraw[i][j]='.';
}

bool horCheck(int i)
{
    if (pos[i].size()<=1) return 1;
    for (int j=1; j<pos[i].size(); j++) if (pos[i][j].XX!=pos[i][0].XX) return 0;
    return 1;
}

bool verCheck(int i)
{
    if (pos[i].size()<=1) return 1;
    for (int j=1; j<pos[i].size(); j++) if (pos[i][j].YY!=pos[i][0].YY) return 0;
    return 1;
}

bool snakeCheck(int i)
{
    return (horCheck(i) || verCheck(i));
}

bool boardCheck()
{
    for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) if (board[i][j]!=redraw[i][j])
        return 0;
    return 1;
}



signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i=0; i<mn; i++) for (int j=0; j<mn; j++) redraw[i][j]='.';

    int T;
    cin>>T;
    
    while (T--)
    {
        cin>>n>>m;
        // cerr<<n<<" "<<m<<endl;
        for (int i=1; i<=n; i++) for (int j=1; j<=m; j++) 
        {
            cin>>board[i][j];
            if (board[i][j]!='.')pos[board[i][j]-'a'].push_back({i, j});
        }
        
        bool linearCheck=1;
        for (int i=0; i<26; i++) if (!snakeCheck(i))
        {
            linearCheck=0;
            break;
        }
        if (!linearCheck)
        {
            cout<<"NO\n";
            refresh();
            continue;
        }

        int ans3=0;
        for (int i=25; i>-1; i--)
        {
            if (pos[i].empty())
            {
                if (pos[i+1].empty()) continue;
                pos[i]=pos[i+1];
                Ans[i]=Ans[i+1];
            }
            else Ans[i]={pos[i][0], pos[i].back()};
            ans3++;
        }

        for (int i=0; i<ans3; i++)
        {
            if (horCheck(i))
            {
                int x=Ans[i].XX.XX, y=Ans[i].XX.YY, yy=Ans[i].YY.YY;
                for (int j=y; j<=yy; j++)  redraw[x][j]=i+'a';
            }
            else
            {
                int x=Ans[i].XX.XX, xx=Ans[i].YY.XX, y=Ans[i].YY.YY;
                for (int j=x; j<=xx; j++) redraw[j][y]=i+'a';
            }
        }
        bool c=boardCheck();
        if (!c) cout<<"NO\n";
        else  
        {
            cout<<"YES\n"<<ans3<<"\n";
            for (int i=0; i<ans3; i++) 
                cout<<Ans[i].XX.XX<<" "<<Ans[i].XX.YY<<" "<<Ans[i].YY.XX<<" "<<Ans[i].YY.YY<<"\n";
        }
        
        refresh();
    }

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/