#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int fr , bck , a[maxn] , res = 1;
multiset<int> st;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    while(fr < n)
    {
        st.insert(a[fr]);
        while(*st.rbegin() - *st.begin() > 1 && fr >= bck)
        {
            st.erase(st.find(a[bck]));
            bck++;
        }
        res = max(res , fr - bck + 1);
   //     cout << fr << " " << bck << endl;
        fr++;
    }
   /* reverse(a , a + n);
    fr = bck = 0;
    st.clear();
    while(fr < n)
    {
        st.insert(a[fr]);
        while(*st.rbegin() - *st.begin() > 1 && fr >= bck)
        {
            st.erase(a[bck]);
            bck++;
        }
        res = max(res , fr - bck + 1);
        fr++;
    }*/
    cout << res;
}