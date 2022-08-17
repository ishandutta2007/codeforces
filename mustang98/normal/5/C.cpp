#include <iostream>
#include <cmath>
#include <set>
#include <string>
#include <stack>

using namespace std;
typedef long long ll;

stack <int> st;
ll l=0, r;
ll maxx=0, kolm=1,rev=false;
string s;

void newlen(ll len)
{
    if (len>maxx) {maxx=len; kolm=1;}
    else if (len==maxx) {kolm++;}
    if (maxx==0) kolm=1;
}

void f()
{
    if (s[l]==')') {l++; return;}
    ll k=0,len=0;
    for (int i=l;i<=r;i++)
    {
        if (s[i]=='(') k++; else k--;
        if (k==0) len=i-l+1;
        if (k==-1)
        {
            newlen(len);
            l+=len;
            return;
        }
        if (i==r)
        {
            newlen(len);
            l+=len;
            if (len==0) l++;
            rev=true;
            return;
        }
    }
}

void fr()
{
    if (s[r]=='(') {r--; return;}
    ll k=0,len=0;
    for (int i=r;i>=l;i--)
    {
        if (s[i]==')') k++; else k--;
        if (k==0) len=r-i+1;
        if (k==-1)
        {
            newlen(len);
            r-=len;
            return;
        }
        if (i==l)
        {
            newlen(len);
            r-=len;
            if (len==0) r--;
            rev=false;
            return;
        }
    }
}

int main()
{
    cin>>s;
    r = s.length()-1;
    while (l<r)
    {
        if (rev) fr();
        else f();
    }
    cout<<maxx<<' '<<kolm;
    return 0;
}