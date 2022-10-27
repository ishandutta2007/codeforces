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
int D[mn]; //original distance of i
vector <pii> A; //sorted array of pair {distance, index}

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for (int i=1; i<=n; i++) 
    {
        cin>>D[i];
        A.push_back({D[i], i});
    }
    sort(A.begin(), A.end());

    deque <pii> Ans; //final answer
    deque <int> firstPath={}; //solving for first path
    deque <int> curPath={};
    int sz=A[n-1].XX;
    firstPath.push_back(A[n-1].YY*2);
    for (int i=n-2; i>=n-sz; i--)
    {
        Ans.push_back({A[i].YY*2, firstPath.back()});
        firstPath.push_back(A[i].YY*2);
    }
    Ans.push_back({firstPath.back(), A[n-1].YY*2-1});
    firstPath.push_back(A[n-1].YY*2-1);

    curPath=firstPath;
    for (int i=1; i<firstPath.size()-1; i++)
    {
        if (curPath[1]==firstPath[i]) curPath.pop_front();
        else curPath.push_front(firstPath[i]);

        int szz=D[(firstPath[i]+1)/2];
        while (curPath.size()>szz) curPath.pop_back();
        Ans.push_back({curPath.back(), curPath.front()-1});
        curPath.push_back(curPath.front()-1);
    }

    for (int i=n-sz-1; i>=0; i--)
    {
        Ans.push_back({firstPath[0], 2*A[i].YY});
        if (A[i].XX==1) Ans.push_back({2*A[i].YY, 2*A[i].YY-1});
        else Ans.push_back({firstPath[A[i].XX-2], 2*A[i].YY-1});
    }

    for (pii P: Ans) cout<<P.XX<<" "<<P.YY<<"\n";
    

}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/