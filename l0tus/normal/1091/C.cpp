#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5+5;

long long n;
vector<long long> D;
int main()
{
    cin >> n;
    for(long long i=1; i*i<=n; i++) if(n%i==0) D.push_back(i);
    for(int i=0; i<D.size(); i++){
        cout << D[i]+(D[i]-1)*n/2 << ' ';
    }
    for(int i=D.size()-1; i>=0; i--){
        int k = n/D[i];
        if(k!=D[i]) cout << k+(k-1)*n/2 << ' ';
    }
}