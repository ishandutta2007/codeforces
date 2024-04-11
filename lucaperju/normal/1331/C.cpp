#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
double rzf[15];
int va[15];
int main ()
{
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int n;
    int rz=n;
    cin>>n;
    if((n&1)+(n&16)==1 || (n&1)+(n&16)==16)
    {
        n^=1;
        n^=16;
    }
    if((n&4)+(n&8)==4 || (n&4)+(n&8)==8)
    {
        n^=4;
        n^=8;
    }
    cout<<n;
}