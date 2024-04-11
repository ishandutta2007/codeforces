#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;

int c[100005];


int main(){
    int i,n,x;
    scanf("%d%d",&n,&x);
    for(i=0;i<n;++i){
        scanf("%d",c+i);
    }
    sort(c,c+n);
    ll r=0;
    for(i=0;i<n;++i){
        r+=((ll)(x))*c[i];
        if(x>1)x--;
    }

    cout<<r<<endl;
    return 0;
}