#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+20;
int a[maxn];
const long long inf = 1e10;
long long _min=inf;
int main()
{
int n;
cin >> n;
string s;
cin >> s;
for(int i=0;i<n;i++)
{
cin >> a[i];
}
for(int i=1;i<n;i++)
{
if(s[i]=='L' && s[i-1] == 'R')
_min=min(_min,(long long)(a[i]-a[i-1])/2);
}
cout <<(_min==inf?-1:_min);
}