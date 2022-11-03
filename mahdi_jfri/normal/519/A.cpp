#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=1e5+20;
map<char,int>a;
ll w,b;
int main()
{
    a['q']=9;
    a['r']=5;
    a['b']=3;
    a['n']=3;
    a['p']=1;
    a['Q']=9;
    a['R']=5;
    a['B']=3;
    a['N']=3;
    a['P']=1;
    a['k']=0;
    a['K']=0;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    for(int i=0 ; i < 8 ; i++)
    {
        cin >> s;
        int j=0;
        while(j<s.size())
        {
            while(s[j]=='.' && j<s.size())
                j++;
            if(j == s.size())
                break;
            if(s[j] < 'a')
                w+=a[s[j]];
            else
                b+=a[s[j]];
            j++;
        }
    }
    if(w==b)
        cout << "Draw";
    else
        cout << ((w>b)?"White":"Black");
}