#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

typedef long long ll;

int a[100005];
int b[100005];

int main(){
    int na,nb,i;
    scanf("%d%d",&na,&nb);
    for(i=0;i<na;++i){
        scanf("%d", a+i);
    }

    for(i=0;i<nb;++i){
        scanf("%d", b+i);
    }

    sort(a,a+na);
    sort(b,b+nb);

    ll r=0;
    int ka=0,kb=nb-1,q=1,d=b[nb-1]-a[0];

    while(d>0){
        int e;
        if(ka+1<na) e=min(d,a[ka+1]-a[ka]);
        else e=d;
        d-=e;
        r+=((ll)e)*q;

        if(kb>0)e=min(d,b[kb]-b[kb-1]);
        else e=d;
        d-=e;
        r+=((ll)e)*q;

        ka++;
        kb--;
        q++;
    }

    cout<<r<<endl;

    return 0;
}