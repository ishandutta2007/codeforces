#include <bits/stdc++.h>
using namespace std;
stack<char> S;
char a[1000010],b[1000010];
int main()
{
    int n,cost=0;
    cin >> n;
    scanf("%s\n%s",a,b);
    for(int i=0; i<n; i++)
    {
        if(a[i]==b[i])
        {
            cost += S.size();
            while(!S.empty()) S.pop();
        }
        else
        {
            if(!S.empty() && a[i]!=S.top())
            {
                cost += S.size();
                while(!S.empty()) S.pop();
            }
            else S.push(a[i]);
        }
    }
    cost += S.size();
    cout << cost;
}