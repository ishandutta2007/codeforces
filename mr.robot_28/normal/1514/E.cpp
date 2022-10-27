#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int mod = 1e9 + 7;
const int N = 200;
int dsu[N], rang[N];
int pred(int a)
{
    if(a == dsu[a]) return a;
    return dsu[a] = pred(dsu[a]);
}
void unite(int a, int b)
{
    a = pred(a);
    b = pred(b);
    if(a != b)
    {
        if(rang[a] < rang[b])
        {
            swap(a, b);
        }
        dsu[b] = a;
        rang[b] += rang[a];
    }
}
signed main()
{
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector <int> index(n);
        vector <int> vec;
        vec.push_back(0);
        for(int i = 1; i < n; i++)
        {
            int l = -1, r = sz(vec);
            while(r - l > 1)
            {
                int midd = (r + l) / 2;
                cout << 1 << " " << i << " " << vec[midd] << endl;
                int x;
                cin >> x;
                assert(x != -1);
                if(x == 1)
                {
                    r = midd;
                }
                else
                {
                    l = midd;
                }
            }
            if(r == sz(vec))
            {
                vec.push_back(i);
            }
            else
            {
                vec.insert(vec.begin() + r, i);
            }
        }
        for(int i = 0; i < n; i++)
        {
       //     cout << vec[i] << " ";
        }
        //cout << '\n';
        vector <bool> used(n);
        int j = sz(vec) - 1;
        for(int i = sz(vec) - 1; i >= 0; i--)
        {
            j = min(j, i);
            index[vec[i]] = i;
            if(j > 0)
            {
                cout << 2 << " " << vec[i] << " " << j << " ";
                for(int t = 0; t < j; t++)
                {
                    cout << vec[t] << " ";
                }
                cout << endl;
                int x;
                cin >> x;
                assert(x != -1);
                if(x)
                {
                    while(j > 0)
                    {
                        j--;
                        cout << 1 << " " << vec[i] << " " <<vec[j] << endl;
                        cin >> x;
                        assert(x != -1);
                        if(x)
                        {
                            if(j == 0)
                            {
                                break;
                            }
                            cout << 2 << " " << vec[i] << " " << j << " ";
                            for(int t = 0; t < j; t++)
                            {
                                cout << vec[t] << " ";
                            }
                            cout << endl;
                            cin >> x;
                            assert(x != -1);
                            if(!x)
                            {
                                break;
                            }
                        }
                    }
                }
            }
            if(i == j)
            {
                used[i] = 1;
            }
        }
        vector <int> nxt(n);
        j = 0;
        for(int i = 0; i < n; i++)
        {
            j = max(j, i + 1);
            while(j < n && !used[j])
            {
                j++;
            }
            for(int k = i; k < j; k++)
            {
                nxt[k] = j - 1;
            }
            i = j - 1;
          //  cout << vec[i] << " " << nxt[i] << "\n";
        }
        cout << 3 << endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == j)
                {
                    cout << 1;
                }
                else if(index[i] < index[j] || nxt[index[j]] >= index[i])
                {
                    cout << 1;
                }
                else
                {
                    cout << 0;
                }
            }
            cout << endl;
        }
        int x;
        cin >> x;
    }
    return 0;
}