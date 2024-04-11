#include <bits/stdc++.h>
using namespace std;

int a[101010];
int le[101010];
int ri[101010];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int v=0;
    for (int i=1;i<=n;i++){
        cin>>a[i];
    }
    for (int i=1;i<=n;i++){
        le[i]=min(le[i-1]+1, a[i]);
    }
    for (int i=n;i>=1;i--){
        ri[i]=min(ri[i+1]+1, a[i]);
        v=max(v, min(le[i], ri[i]));
    }
    cout<<v<<endl;
}