#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 2e5 + 20;
set<int> st;
vector<int> v;
int x[2] , even = 2 , odd = 1 , res , a[maxn];
int main()
{
    int n , m;
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        if(st.find(a[i]) != st.end())
            v.pb(i);
        else
        {
            st.insert(a[i]);
            x[a[i] % 2]++;
            if(a[i] % 2)
            {
                if(x[1] > n / 2)
                    v.pb(i) , x[1]--;
            }
            else
            {
                if(x[0] > n / 2)
                    v.pb(i) , x[0]--;
            }
        }
    }
    res = v.size();
    while(x[0] != n / 2)
    {
        int k = v.back();
        v.pop_back();
        while(st.find(even) != st.end())
            even += 2;
        if(even > m)
        {
            cout << -1;
            return 0;
        }
        st.insert(even);
        a[k] = even;
        x[0]++;
    }
    while(x[1] != n / 2)
    {
        int k = v.back();
        v.pop_back();
        while(st.find(odd) != st.end())
            odd += 2;
        if(odd > m)
        {
            cout << -1;
            return 0;
        }
        st.insert(odd);
        a[k] = odd;
        x[1]++;
    }
    cout << res << endl;
    for(int i = 0; i < n; i++)
        cout << a[i] << " ";
}