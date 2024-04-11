#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
const int N = 100000;

int a[N],c[N],d[N];
ll s;
int n,q,k1,k2;
vector <int> v;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

ll f()
{
    s=0;
    for(int i = k1; i < k2; i ++)
    {
        ll p;
        p = i - max((k1 - 1) ,c[i]);
        p *= min(k2, d[i]) - i;
        s += p * a[i];
    }
    return s;
}

int main()
{
    n = read();
    q = read();
    for(int i = 1; i <= n; i ++)
        a[i] = read();
    for(int i = 1; i < n; i ++)
        a[i] = abs(a[i + 1] - a[i]);
    for(int i = 1; i < n; i ++)
        while(1)
        {
            if(!v.size())
            {
                v.push_back(i);
                break;
            }
            else if(a[v.back()] > a[i])
            {
                c[i] = v.back();
                v.push_back(i);
                break;
            }
            else v.pop_back();
        }
    v.clear();
    for(int i = n - 1; i >= 1; i --)
    {
        d[i] = n;
        while(1)
        {
            if(!v.size())
            {
                v.push_back(i);
                break;
            }
            else if(a[v.back()] > a[i])
            {
                d[i] = v.back();
                v.push_back(i);
                break;
            }
            else if(a[v.back()] == a[i])
            {
                d[i] = v.back();
                v.pop_back();
                v.push_back(i);
                break;
            }
            else v.pop_back();
        }
    }
    for(int i = 1; i <= q; i ++)
    {
        cin >> k1 >> k2;
        cout << f() << "\n";
    }
    return 0;
}