#include <iostream>
typedef long long ll;
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    int n, a[92], i;
    cin>>n;
    for (i = 0; i < n; i++) cin>>a[i];
    if (a[n-1] == 0) {cout<<"UP"; return 0;}
    if (a[n-1] == 15) {cout<<"DOWN"; return 0;}
    if (n == 1) {cout<<-1; return 0;}
    cout<<((a[n-1] > a[n-2])?"UP":"DOWN");
    return 0;
}