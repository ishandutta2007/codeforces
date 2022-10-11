#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int ove = 0, n, s, x, t, ans = 0;
stack <int> st;

int main()
{
    st.push(300);
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &t);
        if (t == 1)
        {
            scanf("%d", &s);
            while (st.top() < s)
            {
                ++ans;
                st.pop();
            }
        }
        else if (t == 2)
        {
            ans += ove;
            ove = 0;
        }
        else if (t == 3)
        {
            scanf("%d", &x);
            if (x >= s)
                st.push(x);
            else ++ans;
        }
        else if (t == 4)
            ove = 0;
        else if (t == 5)
            st.push(300);
        else if (t == 6)
            ++ove;
    }
    printf("%d", ans);
}