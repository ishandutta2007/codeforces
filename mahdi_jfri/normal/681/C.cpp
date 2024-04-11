#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
priority_queue<int , vector<int> , greater<int> >    st;
vector<string> ans;
string s;
inline string to_shit(int n)
{
    stringstream s;
    s << n;
    return s.str();
}
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> s;
        int x;
        if(s != "removeMin")
            scanf("%d", &x);
        if(s == "removeMin")
        {
            if(st.empty())
                ans.pb("insert 1") , st.push(1);
            st.pop();
            ans.pb(s);
        }
        if(s == "insert")
        {
            ans.pb(s + " " + to_shit(x));
            st.push(x);
        }
        if(s == "getMin")
        {
            if(st.empty() || st.top() != x)
            {
                while(!st.empty() && st.top() < x)
                    ans.pb("removeMin") , st.pop();
                if(st.empty() || st.top() != x)
                    ans.pb("insert " + to_shit(x)) , st.push(x);
            }
            ans.pb(s + " " + to_shit(x));
        }
    }
    cout << ans.size() << endl;
    for(auto x : ans)
        printf("%s \n", x.c_str());
}