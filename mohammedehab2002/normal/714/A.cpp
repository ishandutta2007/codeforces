#include <iostream>
using namespace std;
int main()
{
    long long l1,r1,l2,r2,k;
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    long long f=max(l1,l2),s=min(r1,r2);
    if (f<=k && s>=k)
    cout << s-f;
    else
    cout << max(s-f+1,0LL);
}