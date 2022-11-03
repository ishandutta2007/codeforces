#include<bits/stdc++.h>
using namespace std;
#define ll long long
char ch[10] = {'a', 'e', 'i', 'o', 'u', 'y'};
vector<string>s;
string s1;
int p[110];
int res;
bool srch(int i,int z)
{
    for(int j = 0; j < 6; j++)
        if(s[i][z] == ch[j])
            return 1;
    return 0;
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i <= n; i++)
        getline(cin,s1),s.push_back(s1);
    for(int i = 1; i <= n; i++)
    {
        res = 0;
        for(int j = 0; j < s[i].size(); j++)
        {
            if(srch(i,j))
                res++;
        }
        if(res != p[i-1])
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}