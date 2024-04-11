#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a,b;
int main(){
    scanf("%d %d %d",&n,&a,&b);
    printf("%d %d",(1<<a)-1 + n-a,(1<<b)-1 + (1<<b-1)*(n-b));
}