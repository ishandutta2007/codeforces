#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 7001;

vector<int> loh;

bool good(int n)
{
    for (int i = 2; i<=sqrt(n); i++) if (n%i==0)
    {
        int c = 0;
        while (n%i==0) {n/=i; c++;}
        if (c>1) return false;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);   
    bitset<N+1> temp;
    
    for (int i = 1; i<=N; i++) if (good(i)) loh.push_back(i);
    
    vector<bitset<N+1> > all(N+1);
    for (int i = 1; i<=N; i++)
    for (int j = i; j<=N; j+=i) all[j][i] = 1;
    
    vector<bitset<N+1> > cnt(N+1);
    for (int i = 1; i<=N; i++)
    for (int j = 0; j<loh.size()&&loh[j]<=N/i; j++) cnt[i][i*loh[j]] = 1;
    
    int n, q;    
    cin>>n>>q;
    vector<bitset<N+1>> a(n+1);
    int op;
    for (int i = 0; i<q; i++)
    {
        cin>>op;
        if (op==1)
        {
            int x, v;
            cin>>x>>v;
            a[x] = all[v];
        }
        else if (op==2)
        {
            int x, y, z;
            cin>>x>>y>>z;
            a[x] = a[y]^a[z];
        }
        else if (op==3)
        {
            int x, y, z;
            cin>>x>>y>>z;
            a[x] = a[y]&a[z];
        }
        else
        {
            int x, v;
            cin>>x>>v;
            cout << (  ((int)( (a[x] & cnt[v]).count() ) ) & 1   );
        }
    }
}