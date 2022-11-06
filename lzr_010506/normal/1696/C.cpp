#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 998244353;
const int N = 5e4 + 10;
int a[N], b[N];
int cnta[N], cntb[N];
int main()
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 1; i <= n; i ++) scanf("%d", a + i);
        int k;
        scanf("%d", &k);
        for(int i = 1; i <= k; i ++) scanf("%d", b + i);
        for(int i = 1; i <= n; i ++)
        {
            cnta[i] = 1;
            while(a[i])
            {
                if(a[i] % m) break;
                a[i] /= m;
                cnta[i] *= m;
            }
        }
        for(int i = 1; i <= k; i ++)
        {
            cntb[i] = 1;
            while(b[i])
            {
                if(b[i] % m) break;
                b[i] /= m;
                cntb[i] *= m;
            }
        }
        int l = 1, r = 1;
        bool flag = 1;
        while(l <= n && r <= k)
        {
            if(a[l] != b[r])
            {
                flag = 0;
                break;
            }
            else
            {
                if(cnta[l] > cntb[r]) cnta[l] -= cntb[r], ++ r;
                else if(cnta[l] < cntb[r]) cntb[r] -= cnta[l], ++ l;
                else ++ l, ++ r;
            }
        }
        if(!flag || l != n + 1 || r != k + 1) puts("No");
        else cout << "Yes"<<endl;
    }

    return 0;
}