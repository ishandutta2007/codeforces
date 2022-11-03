#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
string s , s1;
set<string> st;
int main()
{
    cin >> s;
    st.insert(s);
    s1 = s;
    char ss = s[s.size() - 1];
    s1.erase(s1.size() - 1, 1);
    s1 = ss + s1;
    st.insert(s1);
    while(s1 != s)
    {
        ss = s1[s1.size() - 1];
        s1.erase(s1.size() - 1 , 1);
        s1 = ss + s1;
        st.insert(s1);
    }
    cout << st.size();
}