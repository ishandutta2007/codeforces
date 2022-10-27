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
#define mod 1000000007
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

int x;
string s;

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int ntest;
    cin>>ntest;
    while (ntest--)
    {
        cin>>x>>s;
        deque <int> DQ={};
        for (int i=0; i<s.size(); i++) DQ.push_back(s[i]-'0');

        int toR=s.size();
        for (int i=0; i<x; i++)
        {
            int u=DQ.front();
            DQ.pop_front();
            toR--;

            int sz=DQ.size();
            // cerr<<u<<" "<<DQ.size()<<"\n";/
            toR=(toR*u)%mod;
            u--;
            while (u--)
            {
                if (DQ.size()>x) break;
                for (int i=0; i<sz; i++) DQ.push_back(DQ[i]);
            }
        }
        cout<<(x+toR)%mod<<"\n";
        // cerr<<"\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/