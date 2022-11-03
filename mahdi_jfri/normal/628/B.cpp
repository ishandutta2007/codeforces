#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s;
ll res;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> s;
    if((s[s.size()-1]-'0')%4 == 0)
        res++;
    for(int i = s.size()-2; i > -1 ; i--)
    {
        if(((s[i]-'0')*10+(s[i+1]-'0'))%4 == 0)
            res+=i+1;
        if((s[i]-'0')%4 == 0)
            res++;
    }
    cout << res;
}