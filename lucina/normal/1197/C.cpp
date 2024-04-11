#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k,a[maxn];
vector<int> b;
long long sum;
/**
6 3
4 8 15 16 23 42
4+7+1+7+21=40
*/
int main(){
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        if(i>1)
        b.push_back(a[i]-a[i-1]);
    }
    sort(b.begin(),b.end());
    for(int i=0;i<n-k;i++){
        sum+=b[i];
    }
    printf("%lld\n",sum);
}