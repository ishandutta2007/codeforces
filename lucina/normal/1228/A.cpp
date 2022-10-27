#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int l,r;
bool test(int x){
    set<int> s;
    int ct = 0;
    while(x > 0){
        s.insert(x % 10);
        ct ++ ;
        x /= 10;
    }
    if((int)s.size() == ct)return true;
    return false;
}

int main(){
    cin >> l >> r;
    for(int i=l;i<=r;i++){
        if(test(i))
            return !printf("%d\n",i);
    }
    printf("-1");
}
/*
    Good Luck
        -Lucina
*/