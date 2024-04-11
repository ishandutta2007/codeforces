#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define p push
#define vi vector<int>
const int maxn = 2e5 + 20;
int a[maxn] , n , javab[maxn];
stack<int> st;
int main()
{
    cin >> n;
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    st.p(-1);
    for(int i = 0; i <= n; i++)
    {
        while(!st.empty() && a[i] < a[st.top()])
        {
            int k = st.top();
            st.pop();
            int j = i - 1 - st.top();
            javab[j] = max(javab[j] , a[k]);
        }
        st.p(i);
    }
    for(int i = n - 1; i > 0; i--)
    {
        if(javab[i] < javab[i + 1])
            javab[i] = javab[i + 1];
    }
    for(int i = 1; i <= n; i++)
        cout << javab[i] << " ";
}