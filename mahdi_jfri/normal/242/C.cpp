#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1e5 + 20;
int h,t;
pair<int,int>q[maxn];
pair<int,int>l;
map <pair <int, int>, bool>mp;
map <pair <int, int>, int>ma;
pair<int,int> pa(int a , int b)
{
    l.first = a;
    l.second = b;
    return l;
}
void bfs(int x,int y)
{
    q[h].first = x;
    q[h++].second = y;
    ma[q[t]] = 0;
    mp[pa(x,y)] = 0;
    while(t < h)
    {
        for(int i = -1; i < 2; i++)
        {
            for(int j = -1; j < 2; j++)
            {
                int a = q[t].first + i;
                int b = q[t].second + j;
                if(mp[pa(a,b)] == 0)
                    continue;
         //       cout << a << " " << b << endl;
                mp[pa(a,b)] = 0;
                q[h].first = a;
                q[h].second = b;
                ma[q[h]] = ma[q[t]] + 1;
                h++;
            }
        }
        t++;
    }
}
int main()
{
    int a1 , b1;
    int x , y;
    cin >> a1 >> b1 >> x >> y;
    int n;
    cin >> n;
    int a , b , c;
    while(n--)
    {
        cin >> c >> a >> b;
        while(a <= b)
            mp[pa(c,a)] = 1,/*cout << pa(c,a).first << " " << pa(c,a).second << endl,*/a++;
    }
    mp[pa(x,y)] = 1;
    ma[pa(x,y)] = -1;
    bfs(a1,b1);
    cout << ma[pa(x,y)];
}