#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define X first
#define Y second
const int maxn = 1e2 + 20;
pair<pair<int , int> , int> a[maxn];
int res[maxn];
int main()
{
    int n , w;
    cin >> n >> w;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].X.X;
        a[i].Y = i;
        w -= a[i].X.X / 2 + a[i].X.X % 2;
        a[i].X.Y = a[i].X.X / 2 + a[i].X.X % 2;
    }
    sort(a , a + n);
  //  for(int i = 0; i < n; i++)
    //{
      //  if(a[i].X.X % 2)
        //{
          //  for(int j = 0; j < n; j++)
            //    if(a[j].X.X == a[i].X.X + 1)
              //  {
                //    a[j].X.Y++;
                  //  w--;
                //}
       // }
    //}
    if(w < 0)
    {
        cout << -1;
        return 0;
    }
    int i = n - 1;
    while(w)
    {
        if(i == -1)
        {
            cout << -1;
            return 0;
        }
        int k = a[i].X.Y;
        a[i].X.Y += min(w , a[i].X.X - a[i].X.Y);
        w -= min(w , a[i].X.X - k);
        i--;
    }
    for(int i = 0; i < n; i++)
        res[a[i].Y] = a[i].X.Y;
    for(int i = 0; i < n; i++)
        cout << res[i] << " ";
}