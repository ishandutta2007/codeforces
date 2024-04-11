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

string tryDivideDigit(char x)
{
    string ret;
    ret.assign(n, '0');
    int lst=-1;
    for (int i=0; i<S.size(); i++) 
    {
        if (S[i]<x) ret[i]='1', lst=i;
        else if (S[i]>x) ret[i]='2';
    }
    for (int i=0; i<S.size(); i++) if (S[i]==x) 
    {
        if (i<lst) ret[i]='2';
        else ret[i]='1';
    }
    return ret;
}

bool checkString(string A)
{
    string str1="", str2="";
    for (int i=0; i<n; i++) if (A[i]=='1') str1.push_back(S[i]);
    for (int i=0; i<n; i++) if (A[i]=='2') str2.push_back(S[i]);
    str1+=str2;
    for (int i=1; i<n; i++) if (str1[i]<str1[i-1]) return 0;
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

    int T;
    cin>>T;
    while (T--)
    {
        cin>>n>>S;
        string K;
        bool f=0;
        for (int i='0'; i<='9'; i++) 
        {
            K=tryDivideDigit(i);
            if (checkString(K))
            {
                f=1;
                cout<<K<<"\n";
                break;
            }
        }
        if (!f) cout<<"-\n";
    }
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/