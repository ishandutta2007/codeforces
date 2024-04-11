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

int n, k;
string S;

bool specCase(string s)
{
    for (char c:s) if (c!='9') return 0;
    return 1;
}

string add1(string s)
{
    s="0"+s;
    string ret=s;
    int xet=s.back()-'0'+1;
    int nho=xet/10;
    for (int i=s.size()-1; i>-1; i--)
    {
        ret[i]=xet%10+'0';
        if (i>0) xet=ret[i-1]+nho-'0';
        nho=xet/10;
    }

    if (ret[0]=='0') ret=ret.substr(1, ret.size()-1);
    return ret;
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

    cin>>n>>k>>S;

    string Sk1=S.substr(0, k);
    if (specCase(Sk1))
    {
        cout<<n<<"\n";
        for (int i=1; i<=n; i++) cout<<9;
    }
    else
    {
        string Sk2=add1(Sk1);
        while (Sk1.size()<n)
        {
            Sk1+=Sk1.substr(0, k);
        }
        while (Sk1.size()>n) Sk1.pop_back();

        while (Sk2.size()<n)
        {
            Sk2+=Sk2.substr(0, k);
        }
        while (Sk2.size()>n) Sk2.pop_back();

        cerr<<Sk1<<"\n"<<Sk2<<"\n";

        cout<<n<<"\n";
        if (Sk1<S) cout<<Sk2;
        else cout<<Sk1;
    }
    
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/