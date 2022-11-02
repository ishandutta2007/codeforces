#include <bits/stdc++.h>
using namespace std;

int a[101010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a[i];
        while (a[i]%2==0) a[i]/=2;
        while (a[i]%3==0) a[i]/=3;
    }
    for (int i=1;i<n;i++){
        if (a[i]!=a[0]) {
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
}