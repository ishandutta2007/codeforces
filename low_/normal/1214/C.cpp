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
#define mn 100005
#define inf 4444444444444444444
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int n;
string S;

bool checkRound1(string S)
{
    int cntO=0, cntC=0;
    for (int i=0; i<n; i++) 
    {
        if (S[i]=='(') cntO++;
        else cntC++;
    }
    // cerr<<cntO<<" "<<cntC<<endl;
    if (cntO==cntC) return 1;
    else return 0;
}

int checkRound2(string S) // return the first closed bracket that misplaced, or report that the string is correct already
{
    int cnt=0;
    for (int i=0; i<n; i++)
    {
        if (S[i]=='(') cnt++;
        else cnt--;
        if (cnt<0) return i;
    }
    return -1;
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

    cin>>n>>S;
    if (!checkRound1(S)) cout<<"No";
    else 
    {
        int k=checkRound2(S);
        // cerr<<k<<endl;
        if (k==-1) cout<<"Yes";
        else
        {
            for (int i=k; i<n-1; i++) S[i]=S[i+1];
            S[n-1]=')';
            k=checkRound2(S);
            if (k==-1) cout<<"Yes";
            else cout<<"No";
        }
        
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/