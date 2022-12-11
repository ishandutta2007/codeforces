#include <bits/stdc++.h>
#define va first
#define vb second
using namespace std;
const int MN =1e5;
char t[3],a[5][3];
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> t;
    bool ispos = false;
    for(int i=0; i<5; i++){
        cin >> a[i];
        if(t[0]==a[i][0] || t[1]==a[i][1]) ispos = true;
    }
    if(ispos) cout << "YES";
    else cout << "NO";

}