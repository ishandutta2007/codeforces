#include <iostream>
#include <string>

using namespace std;

typedef long long ll;
string a, b;

int main()
{
    cin >> a >> b;
    int la = a.size();
    int lb = b.size();

    ll cnt0 = 0, cnt1 = 0, ans = 0;

    for (int i = 0; i <= lb - la; i++) {
        if (b[i] == '0') cnt0++;
        else cnt1++;
    }

//    cerr << a[0] << " " << cnt0 << " " << cnt1 << endl;
    if (a[0] == '0') ans += cnt1;
    else ans += cnt0;

    for (int i = 1; i < la; i++) {
        if (b[lb - la + i] == '0') cnt0++;
        else cnt1++;

        if (b[i - 1] == '0') cnt0--;
        else cnt1--;

//        cerr << a[i] << " " << cnt0 << " " << cnt1 << endl;
        if (a[i] == '0') ans += cnt1;
        else ans += cnt0;
    }
    cout << ans << endl;
    return 0;
}