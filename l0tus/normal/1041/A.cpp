#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,str[1010];
    cin >> n;
    for(int i=0; i<n; i++) cin >> str[i];
    sort(str,str+n);
    cout << str[n-1]-str[0]-(n-1);
}