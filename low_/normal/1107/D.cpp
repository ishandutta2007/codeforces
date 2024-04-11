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
// #define int long long
#define mn 100005
#define mod 1000000009
#define FLN "test" 
#define pii pair <int, int>
#define XX first
#define YY second

string toBin(string Hex)
{
    string ret="", temp;
    int k;
    for (int i=0; i<Hex.size(); i++)
    {
        if (Hex[i]>='0' && Hex[i]<='9') k=Hex[i]-'0';
        else k=Hex[i]-'A'+10;

        temp="";
        for (int j=0; j<4; j++) 
        {
            temp+='0'+(k%2);
            k/=2;
        }
        ret+=temp[3];
        ret+=temp[2];
        ret+=temp[1];
        ret+=temp[0];
    }
    return ret;

}

string B[5205];
int GCD(int u, int v)
{
    if (v==0) return u;
    return GCD(v, u%v);
}

int C[5205];

signed main()
{
#ifdef lowie
    freopen(FLN".inp", "r", stdin);
    freopen(FLN".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    string tmp;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>tmp;
        B[i]=toBin(tmp);
    }

    for (int i=0; i<n; i++) 
    {
        for (int j=0; j<n; j++) 
        {
            if (i>0) if (B[i][j]!=B[i-1][j]) C[i]=1;
            if (j>0) if (B[i][j]!=B[i][j-1]) C[j]=1;
        }
    }

    int ans=n;
    for (int i=0; i<5205; i++) if (C[i]==1) ans=GCD(i, ans);
    cout<<ans;
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/