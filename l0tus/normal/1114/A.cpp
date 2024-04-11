#include <bits/stdc++.h>
using namespace std;
const int MN = 1e5+5;
int N,K,X,Y,Z,A,B,C,cnt,val,res,ans;
string S;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    cin >> X >> Y >> Z;
    cin >> A >> B >> C;
    bool isokay = true;
    if(A<X) isokay = false;
    if(A+B<X+Y) isokay = false;
    if(A+B+C<X+Y+Z) isokay = false;
    if(isokay) cout << "YES";
    else cout << "NO";
}