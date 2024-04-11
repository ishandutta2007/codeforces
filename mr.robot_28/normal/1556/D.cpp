#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
using namespace std;
const int N = 1e6;
const int mod = 1e9 + 7;
vector <int> v = {1, 6, 4, 2, 3, 5, 4};
int query1(int a, int b){
//    return v[a - 1] | v[b - 1];
    cout << "or " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}
int query2(int a, int b){
  //  return v[a - 1] & v[b - 1];
    cout << "and " << a << " " << b << endl;
    int x;
    cin >> x;
    return x;
}
signed main()
{
    int n, k;
    cin >> n >> k;
    vector <int> mass1(n), mass2(n);
    for(int i = 1; i < n; i++){
        mass1[i] = query1(1, i + 1);
        mass2[i] = query2(1, i + 1);
    }
    int a = query1(2, 3);
    int b = query2(2, 3);
    vector <pair <int, int> > res(n);
    for(int j = 0; j < n; j++){
        res[j].Y = j;
    }
    for(int i = 29; i >= 0; i--){
        bool fl = 0;
        for(int j = 1; j < n; j++){
            int _xor = mass1[j] - mass2[j];
            if((_xor & (1 << i)) == 0){
                fl = 1;
                if(mass2[j] & (1 << i)){
                    res[0].X += (1 << i);
                }
                break;
            }
        }
        if(!fl){
            if((b & (1 << i)) == 0){
                res[0].X += (1 << i);
            }
        }
        int bit = res[0].X & (1 << i);
        for(int j = 1; j < n; j++){
            int _xor = (mass1[j] - mass2[j]) & (1 << i);
            res[j].X += bit ^ _xor;
        }
    }/*
    for(int j = 0; j < n; j++){
        cout << res[j].X << " ";
    }*/
    sort(res.begin(), res.end());
    cout << "finish ";
    cout << res[k - 1].X << endl;
    return 0;
}