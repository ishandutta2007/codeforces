#include <iostream>
using namespace std;
int p,q;
int x,y;

bool possible(int x,int y){
    long long bm=1LL*p*p+1LL*q*q;
    if(bm==0){
        if((x || y)) return false;
        else return true;
    } else if((((-1LL*p*x-1LL*q*y)%bm) || ((-1LL*q*x+1LL*p*y)%bm))) return false;
    else return true;
}

int main()
{
    bool ans=false;
    int ax,ay;
    cin>>ax>>ay>>x>>y>>p>>q;
    int i;
    int tmp;
    for(i=0;i<4;++i){
        x-=ax; y-=ay;
        ans=ans||(possible(x,y) || possible(-y,x));
        x+=ax; y+=ay;
        tmp=ax; ax=ay; ay=-tmp;
    }
    if(ans) cout<<"YES";
    else cout<<"NO";
    return 0;
}