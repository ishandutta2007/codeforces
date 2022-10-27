//**KEEP IT SHORT AND SIMPLE**
#include <bits/stdc++.h>
#define REP(i,a,b) for (int i = a; i < b; i++)
using namespace std;
const int N = 1e5 + 5;
int n, m, a, b, rt, ct, arr[N], sz[N], nx[N], ls[N];
int bucket(int x)
{
    if(x >= n)
        return ct;
    return x / rt;
}
void update(int i)
{
    if(bucket(i) != bucket(i + arr[i]))
    {
        nx[i] = min(n, i + arr[i]);
        sz[i] = 1;
        ls[i] = i;
    }
    else
    {
        nx[i] = nx[i + arr[i]];
        sz[i] = 1 + sz[i + arr[i]];
        ls[i] = ls[i + arr[i]];
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin >> n >> m;
    int c;
    rt = sqrt(n);
    ct = (n + rt - 1) / rt;
    REP(i, 0, n)
        cin >> arr[i];
    for(int i = n - 1;i >= 0;i--)
        update(i);
    while(m--)
    {
        cin >> c;
        if(!c)
        {
            cin >> a >> b;
            --a;
            arr[a] = b;
            for(int i = a;i % rt;--i)
                update(i);
            update(a / rt * rt);
        }
        else
        {
            cin >> a;
            --a;
            int last = 0, jump = 0;
            for(int i = a;i < n;i = nx[i])
            {
                jump += sz[i];
                last = ls[i];
            }
            cout << last + 1 << ' ' << jump << "\n";
        }
    }
    return 0;
}