#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m, fl;
int main(){
    scanf("%d %d",&n,&m);
    int a = (n - m) / 2 + 1;
    for(int i=1;i<=n;i++) printf("%d", i % a == 0);
}