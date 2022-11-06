#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;

string s, s1, s2, s3;
int f[10000006], n, k;
char get(int n, int k)
{
    //cout << n << ' '<<k<<endl;
    if (n == 0)
        return s[k];

    if (k < s1.size())
        return s1[k];

    if (k == s1.size())
        return '"';

    if (k == s1.size() + f[n-1]+1)
        return '"';

    if (k < s1.size() + f[n-1]+1)
        return get(n-1, k - s1.size()-1);

    if (k < s1.size() + f[n-1] + 1 + s2.size()+1)
        return s2[k-s1.size()-f[n-1]-2];

    if (k == s1.size()+f[n-1]+1+s2.size()+1)
        return '"';

    if (k == s1.size() + f[n-1]+1+s2.size()+1+f[n-1]+1)
        return '"';

    if (k < s1.size() + f[n-1] + 1 + s2.size()+1+f[n-1]+1)
        return get(n-1, k - s1.size() - f[n-1] - 1 - s2.size() - 1-1);

    return s3[k-s1.size()-f[n-1]-1-s2.size()-1-f[n-1]-1-1];
}

signed main()
{
    s1 = "What are you doing while sending ";
    s2 = "? Are you busy? Will you send ";
    s3 = "?";
    s = "What are you doing at the end of the world? Are you busy? Will you save us?";
    f[0] = s.size();
    for (int i = 1; i <= 100000; i++)
        f[i] = f[i-1]*2 + 4 + s1.size()+s2.size() + s3.size();
    int q;
    cin >> q;
    for (int j = 0; j < q; j++){
            cin >> n >> k;
    //cout << f[n] <<' ' <<k <<endl;
    if (k > f[n])
        cout << '.';
    else
        cout << get(n, k-1);
    }
    return 0;
}