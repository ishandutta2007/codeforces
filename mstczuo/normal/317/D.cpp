# include <iostream>
# include <cstdio>
const int sg[] = {
    0,1,2,1,4,
    3,2,1,5,6,
    2,1,8,7,5,
    9,8,7,3,4,
    7,4,2,1,10,
    9,3,6,11,12
};

using namespace std;

int c[32],rem,res;
bool v[100000];

int main()
{
    int n; cin >> n; rem = n;
    for (int i = 2; i * i <= n; ++i) {
        if (v[i]) continue;
        int a = i;
        int d = 1;
        while (a<=n/i){
            a*=i, ++d;
            if(a<=n/a)
            v[a]=true;
        }
        
        rem -= d;
        res ^= sg[d];
    }
    res ^= (rem&1);
    cout << (res ? "Vasya" : "Petya") << endl;
    
}