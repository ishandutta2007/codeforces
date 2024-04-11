#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 100007;
ll c[N] = {0};
int n;
bool good(int t)
{
    int ch = t;
    ll ok = 1;
    int b = 0;
    int f;
    for(int i = t; i < n; i ++)
    {
        if(c[i] < ok * 2) b ++;
        else if(c[i] > ok * 2)  return false;
        else
        {
            f = 0;
            for(; i < n; i ++)
            {
                if(c[i] == ok * 2) f ++ ;
                else
                {
                    i --;
                    break;
                }
            }
            if(f >= ch)
            {
                ok = ok * 2;
                b += f - ch;
            }
            else
            {
                b -= (ch - f);
                if(b < 0) b = 0;
                ch = f;
                ok = ok * 2;
            }
        }
    }
    if(b > ch)return false;
    return true;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n; i ++)
        scanf("%I64d",&c[i]);
    int e = 0;
    for(int i = 0; i < n; i ++)
    {
        if(c[i] == 1) e ++;
        else break;
    }
    int a = 0;
    int b = e + 1;
    int t;
    for(; a + 1 < b;)
    {
        t = (a + b) / 2;
        if(good(t)) b = t;
        else a = t;
    }
    if(b == e + 1) cout << -1;
    else
        for(int i = b; i <= e; i ++)
            printf("%d ",i);
    return 0;
}