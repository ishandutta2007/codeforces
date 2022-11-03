#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
stack<int> stck;
multiset<char> st;
string res;
bool is[maxn];
int main()
{
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        st.insert(s[i]);
    for(int i = 0; st.size();)
    {
        while(stck.size() && s[stck.top()] == *st.begin())
        {
            res += s[stck.top()];
            is[stck.top()] = 0;
            st.erase(st.begin());
            stck.pop();
            if(!stck.empty() && !is[stck.top()])
                st.insert(s[stck.top()]) , is[stck.top()] = 1;
        }
        while(i < s.size() && s[i] != *st.begin())
        {
            if(!stck.empty() && is[stck.top()])
            {
                is[stck.top()] = 0;
                st.erase(st.find(s[stck.top()]));
            }
            st.erase(st.find(s[i]));
            stck.push(i);
            i++;
        }
        if(i < s.size())
        {
            res += s[i];
            i++;
            st.erase(st.begin());
            if(!stck.empty() && !is[stck.top()])
                st.insert(s[stck.top()]) , is[stck.top()] = 1;
        }
    }
  //  while(!stck.empty())
    //    res += stck.top() , stck.pop();
    cout << res;
}