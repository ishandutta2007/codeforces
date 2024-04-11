#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;

int b[N];
vector<int> a[N];

int main() 
{
    int T;
    scanf("%d", &T);
    while(T --)
    {
        int n;
        scanf("%d", &n);
        int k = 0;
        int p = -1;
        for (int i = 0; i <= n + 1; i ++) a[i].clear(); 
        for (int i = 1; i <= n; i ++) 
        {
            scanf("%d", b + i);
            if (b[i] < i)  k = max(k, b[i]);
            else k = max(k, i);
            if (b[i] == n + 1) p = n + 1; 
            if (b[i] == 0) p = 0; 
            a[b[i]].push_back(i);
        }
        vector<int> ans;
        while(p != -1)
        {
            int z = -1;
            for (auto x : a[p]) 
                if (!a[x].empty()) 
                    z = x;
            for (auto x : a[p]) 
                if (x != z) ans.push_back(x);
            for (auto x : a[p]) 
                if (x == z) ans.push_back(x);
            p = z;
        }
        printf("%d\n", k);
        for (auto x : ans)  printf("%d ", x);
        printf("\n");
    }
    return 0;
}