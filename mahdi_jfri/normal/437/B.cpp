#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
int sum , limit;
stack<int> st;
int lb(int a)
{
    int res = 0;
    while(a % 2 == 0)
        res++ , a /= 2;
    return res;
}
int main()
{
    cin >> sum >> limit;
    for(int i = limit; i > 0 && sum > 0; i--)
    {
        int k = (1 << lb(i));
        if(sum - k >= 0)
        {
            sum -= k;
            st.push(i);
        }
    }
    if(sum > 0)
    {
        cout << -1;
        return 0;
    }
    cout << st.size() << endl;
    while(!st.empty())
        cout << st.top() << " " , st.pop();
}