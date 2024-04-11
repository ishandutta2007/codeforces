#include<iostream>
using namespace std;
typedef long long LL;

int main(){
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    cout << min((n/m+1)*b,min(n*a,(n%m)*a+(n/m)*b)) << endl;

}