#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define front fffront
#define back bbbbacccckkkk
const int maxn = 1e5 + 20;
int a[maxn] , front , back, b = -1 , c = -1, ans = maxn, t = 1;
map<int , int> mp;
int main()
{
    int n , k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    mp[a[1]] = 1;
    front = 2;
    if(t == k)
    {
        b = 1;
        c = 1;
        ans = 1;
    }
    while(front <= n)
    {
        if(!mp[a[front]])
        {
            mp[a[front]]++;
            t++;
        }
        else
        {
            mp[a[front]]++;
        }
        if(t == k)
        {
            if(front - back < ans)
            {
                ans = front - back;
                b = front;
                c = back + 1;
            }
            back++;
            while(mp[a[back]] > 1 && back <= front)
            {
                mp[a[back]]--;
                if(front - back < ans)
                {
                    ans = front - back;
                    b = front;
                    c = back + 1;
                }
                back++;
            }
            t--;
            back--;
        }
        front++;
    }
    cout << c << " " << b;
}