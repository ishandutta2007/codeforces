#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

int a[10000];
int mx[10000];

int n;

int getmax(int i){
    if (i>n) return 0;
    mx[i]=max(getmax(i*2), getmax(i*2+1))+a[i];
    return mx[i];
}

int v=0;

void go(int i, int h, int ne){
    if (i>n) return;
    int lol=ne-(mx[i]+h);
    //cout<<i<<" "<<mx[i]<<" "<<lol<<" "<<ne<<endl;
    v+=lol;
    go(i*2, h+lol+a[i], ne);
    go(i*2+1, h+lol+a[i], ne);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    n=(1<<(n+1))-1;
    for (int i=2;i<=n;i++){
        cin>>a[i];
    }
    go(1, 0, getmax(1));
    cout<<v<<endl;
}