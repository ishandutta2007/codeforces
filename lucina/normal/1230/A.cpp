#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e5+10;
int a[10];

int main(){
    for(int i=1;i<=4;i++)
        cin>>a[i];
    sort(a+1,a+5);
    return !printf(((a[4]+a[1] == a[2]+ a[3])||(a[1]+a[2]+a[3] == a[4]))?"YES\n":"NO\n");
}
/*
    Good Luck
        -Lucina
*/