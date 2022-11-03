#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int maxn = 1024;
ll a[maxn + 20] , _min = 1e18, _max = -1 , y , b[maxn + 20] , c[maxn + 20];
int main()
{
    int n , k , x;
    cin >> n >> k >> x;
    for(int i = 0; i < n; i++)
    {
        cin >> y;
        b[y]++;
     //   if(b[y] == 1)
     //       st[0].insert(y);
    }
    for(int i = 0; i < k; i++)
    {
        int m = 1;
        for(int z = 0; z < maxn + 1; z++)
        {
        //    if(b[z])
        //    cout << z << " " << m << endl;
            if(m % 2 == 0)
            {
                c[z ^ x] += b[z] / 2;
                c[z] += b[z] - (b[z] / 2);
            }
            else
            {
                c[z ^ x] += b[z] / 2 + (b[z] % 2);
                c[z] += b[z] / 2;
            }
      //      if(c[z])
        //        st[i + 1].insert(z);
          //  if(c[z ^ x])
            //    st[i + 1].insert(z);
            m += b[z];
        }
        for(int j = 0; j < maxn + 1; j++)
            b[j] = c[j] , c[j] = 0;
    }
    for(ll i = 0; i <= maxn; i++)
        if(b[i])
            _max = max(i , _max) , _min = min(i , _min);
    cout << _max << " " << _min;
}