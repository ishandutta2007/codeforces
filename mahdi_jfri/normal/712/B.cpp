#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
const int maxn=1e5+20;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int n=s.size();
    int x=0,y=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R')
            x++;
        else if(s[i]=='L')
            x--;
        else if(s[i]=='U')
            y++;
        else
            y--;
    }
    if(x<0)
        x=-x;
    if(y<0)
        y=-y;
    x+=y;
    if(x%2!=0)
    {
        cout<<-1;
        return 0;
    }
    cout<<(x/2);
}