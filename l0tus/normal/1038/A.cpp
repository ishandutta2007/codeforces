#include <bits/stdc++.h>
using namespace std;

int n,k,num[30],m=100010;
char str[100010];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    cin >> str;
    for(int i=0; i<strlen(str); i++)
        num[str[i]-'A']++;
    for(int i=0; i<k; i++)
        m = min(m,num[i]);
    cout << m*k;
}