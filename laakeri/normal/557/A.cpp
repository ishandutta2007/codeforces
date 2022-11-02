#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int mi[10];
int ma[10];
int a[10];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=0;i<3;i++){
        cin>>mi[i]>>ma[i];
        n-=mi[i];
        a[i]=mi[i];
    }
    for (int i=0;i<3;i++){
        int t=min(n, ma[i]-a[i]);
        n-=t;
        a[i]+=t;
    }
    for (int i=0;i<3;i++){
        cout<<a[i]<<" ";
    }
}