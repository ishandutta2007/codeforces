#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e4 + 20;
string a , b;
int main()
{
    cin >> a >> b;
    int n;
    cin >> n;
    cout << a << " " << b << endl;
    for(int i = 0; i < n; i++)
    {
        string s , s1;
        cin >> s >> s1;
        if(a == s)
        {
            swap(a , s1);
        }
        else
            swap(b , s1);
        cout << a << " " << b << endl;
    }
}