#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long int ll;

int main()
{
    int m[100001];
    int n, a, b,c;
    cin>>n;
    if(n == 1)
    {
        cin>>a;
        if (a == 15) {cout<<"DOWN"; return 0;}
        if (a == 0) {cout<<"UP"; return 0;}
        cout<<-1;
        return 0;
    }
    for(int i=0;i<n-2;i++) cin>>c;
    cin>>a>>b;
    if (b == 15) {cout<<"DOWN"; return 0;}
    if (b == 0) {cout<<"UP"; return 0;}
    if (b < a) cout<<"DOWN";
    else cout<<"UP";
    return 0;
}