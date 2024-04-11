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

string Add(string A, string B)
{
    string t1=A, t2=B;
    reverse(t1.begin(), t1.end());
    reverse(t2.begin(), t2.end());
    t1+='0', t2+='0';
    while (t1.size()<t2.size()) t1+='0';
    while (t2.size()<t1.size()) t2+='0';
    
    string ret;
    ret.assign(t1.size(), '0');
    int xet=0, nho=0;
    for (int i=0; i<ret.size(); i++) 
    {
        xet=t1[i]+t2[i]-96+nho;
        nho=xet/10;
        ret[i]=xet%10+48;
    }
    while (!ret.empty())
    {
        if (ret.back()!='0') break;
        ret.pop_back();
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

string MIN(string A, string B)
{
    if (A.size()>B.size()) return B;
    if (B.size()>A.size()) return A;
    for (int i=0; i<A.size(); i++) 
    {
        if (A[i]>B[i]) return B;
        else if (A[i]<B[i])return A;
    }
    return A;
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
    int n;
    string S;
    cin>>n>>S;
    if (n%2==0)
    {
        if (S[n/2]=='0')
        {
            int l=n/2, r=n/2;
            while (l>-1)
            {
                if (S[l]!='0') break;
                l--;
            }
            while (r<n)
            {
                if (S[r]!='0') break;
                r++;
            }
            
            string ans;
            if (l>-1) ans=Add(S.substr(0, l), S.substr(l,n-l));
            else ans=Add(S.substr(0, r), S.substr(r,n-r));
            
            if (r<n) ans=MIN(ans, Add(S.substr(0, r), S.substr(r,n-r)));
            cout<<ans;
        }
        else
        {
            string A=S.substr(0, n/2), B=S.substr(n/2, n/2);
            cout<<Add(A, B);
        }
    }
    else
    {
        int l=n/2, r=n/2+1;
        while (l>-1)
        {
            if (S[l]!='0') break;
            l--;
        }
        while (r<n)
        {
            if (S[r]!='0') break;
            r++;
        }

        string ans;
        if (l>-1) ans=Add(S.substr(0, l), S.substr(l,n-l));
        else ans=Add(S.substr(0, r), S.substr(r,n-r));
        
        if (r<n) ans=MIN(ans, Add(S.substr(0, r), S.substr(r,n-r)));

        cout<<ans;
    }
    
}

// PLEASE REMOVE cout AND cerr DEBUG LINES BEFORE SUBMITTING PROBLEMS
// Code by low_
// Contact me via mail: dung.totuan01@gmail.com
// ...or codeforces: www.codeforces.com/profiles/low_
// ...or if you're interested in food: www.instagram.com/lowie_review/