#include <bits/stdc++.h>
#define ll long long
using namespace std;
int g[2005][2005];
map<ll, int> res;
int main()
{
    int n;
    while(cin >> n)
    {
        bool flag = true;
        for(int i = 0; i < n; i ++)
            for(int j = 0; j < n; j ++)
                scanf("%d", &g[i][j]);
        for(int i = 0; i < n; i ++)
        {
            for(int j = 0; j < n; j ++)
            {	
                if(i == j && g[i][j])
                {
                    flag = false;
                    break;
                }
                if(i != j && g[i][j] == 0)
                {
                    flag = false;
                    break;
                }
                if(g[i][j] != g[j][i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == false) break;
        }
        if(flag == true)
        {
            for(int i = 0; i < n; i ++)
                res[2 * g[1][i]] = 1;
            for(int i = 0; i < n; i ++)
            {
                for(int j = 0; j < n; j ++)
                    if((g[i][j] != fabs(g[1][i] - g[1][j])) && (res[g[1][i] + g[1][j] - g[i][j]] != 1))
                    {
                        flag = false;
                        break;
                    }
                if(flag == false) break;
            }
        }
        if(flag == true) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        res.clear();
    }
    return 0;
}