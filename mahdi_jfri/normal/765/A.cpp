#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
string s[maxn] , s1;
int a , b;
int main()
{
    int n;
    cin >> n;
    cin >> s1;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        if(s[i].substr(0 , 3) == s1)
            a++;
        if(s[i].substr(5) == s1)
            b++;
    }
    if((a - b) & 1)
        cout << "contest";
    else
        cout << "home";
}