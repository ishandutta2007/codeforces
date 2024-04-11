#include <iostream>
#include <string.h>
using namespace std;
main()
{
    int len[101], n, k, cur, mi, ma, i, l = 0;
    string s;
    memset(len,0,sizeof(len));
    cin>>n>>k;
    for (i = 0; i < n; i++) cin>>s, len[s.length()]++;
    cin>>s;
    for (i = 1; i < s.length(); i++) l += len[i];
    mi = l + 1 + 5*((l)/k);
    ma = l + len[s.length()] + 5*((l + len[s.length()] - 1)/k);
    cout<<mi<<" "<<ma;
}