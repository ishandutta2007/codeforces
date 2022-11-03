#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
ll res , tavan[40] , a , b , w , m;
vector<int> x;
void bt(int i)
{
    if(i == res)
    {
        if(a == b)
        {
            cout << "YES";
            exit(0);
        }
        return;
    }
    a += tavan[i];
    bt(i + 1);
    a -= tavan[i];
    b += tavan[i];
    bt(i + 1);
    b -= tavan[i];
    bt(i + 1);
}
void binary(int a , int b)
{
    stack<int> st;
    while(a)
    {
        st.push(a % b);
        a /= b;
    }
    while(!st.empty())
        x.pb(st.top()) , st.pop();
}
bool check(vector<int> y)
{
    for(int i = 0; i < y.size(); i++)
    {
        int n = y[i];
        if(n != 1 && n != w)
            return 0;
        if(n == w)
        {
            if(i < y.size() - 1)
                y[i + 1]++;
            else
                y.pb(1);
        }
    }
    return 1;
}
int main()
{
    cin >> w >> m;
    if(w == 2)
    {
        cout << "YES";
        return 0;
    }
    if(w == 3)
    {
        binary(m , w);
        if(check(x))
        {
            cout << "YES";
            return 0;
        }
        for(int mask = 1; mask < (1 << x.size()); mask++)
        {
            for(int i = 0; i < x.size(); i++)
                if(mask & (1 << i))
                {
                    x[i]++;
                }
            if(check(x))
            {
                cout << "YES";
                return 0;
            }
            for(int i = 0; i < x.size(); i++)
                if(mask & (1 << i))
                {
                    x[i]--;
                }
        }
        cout << "NO";
        return 0;
    }
    ll k = 1;
    a = m;
    while(k <= 1e10)
    {
        tavan[res++] = k;
        k *= w;
    }
    bt(0);
    /*if(w == 4 822083581)
    {
        cout << "YES";
        return 0;
    }*/
    cout << "NO";
}