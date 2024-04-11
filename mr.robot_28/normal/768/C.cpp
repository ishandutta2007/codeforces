#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
  //  ios_base::sync_with_stdio(false);
  //  cin.tie(NULL);
    //cout.tie(NULL);
    int n, k, x;
    cin >> n >> k >> x;
    vector <int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int mass[2][1024];
    for(int i = 0; i < n; i++)
    {
        mass[i % 2][a[i]]++;
    }
    int mass1[2][1024];
    int mass2[2][1024];
    while(k--)
    {
        for(int i = 0; i < 1024; i++)
        {
            mass1[0][i ^ x] = mass[0][i];
        }
        for(int t= 0; t < 2; t++)
        {
            for(int a = 0; a < 1024; a++)
            {
                mass2[t][a] = 0;
            }
        }
        int it = 0;
        for(int a =0 ; a < 1024; a++)
        {
            int cnt = mass1[0][a] + mass[1][a];
            int len1 = (cnt + 1) / 2;
            int len2 = cnt / 2;
            if(it % 2 == 0)
            {
                mass2[0][a] += len1;
                mass2[1][a] += len2;
            }
            else
            {
                mass2[0][a] += len2;
                mass2[1][a] += len1;
            }
            it += cnt;
        }
        for(int t =0 ; t < 2; t++)
        {
            for(int a =0; a < 1024; a++)
            {
                mass[t][a] = mass2[t][a];
            }
        }
    }
    int mina = 1e9;
    int maxa =0 ;
    for(int a = 0; a < 1024; a++)
    {
        int cnt = mass[0][a] + mass[1][a];
        if(cnt != 0)
        {
            mina = min(mina, a);
            maxa = max(maxa, a);
        }
    }
    cout << maxa << " " << mina;
    return 0;
}