#include<bits/stdc++.h>
using namespace std;
#define int long long
int mp[100001];
main() {
    int n,k;
    string s;
    cin>>n>>k>>s;
    if(k==n)return 0;
    for(int x=0;x<=n;x++)
    mp[s[x]]++;
    char ch='a';
    while(k>=0)
    {
        k-=mp[ch];
        ch++;
    }
    ch-=2;
    k+=mp[ch+1];
    for(int x=0;x<n;x++)
    if(s[x]>ch+1||(s[x]==ch+1&&!k))cout<<s[x];
    else k-=(s[x]==ch+1);
}