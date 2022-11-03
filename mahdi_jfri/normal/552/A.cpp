#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e2 + 20;
int x1[maxn] , x2[maxn] , y1[maxn] , y2[maxn] , res;
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
    for(int i = 0; i < 101; i++)
        for(int j = 0; j < 101; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(i >= x1[k] && i <= x2[k] && j >= y1[k] && j <= y2[k])
                    res++;
            }
        }
    cout << res << endl;
}