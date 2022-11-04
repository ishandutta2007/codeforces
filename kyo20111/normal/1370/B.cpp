#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, a[2020];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=2*n;i++) scanf("%d",a+i);
        vector<int> v[2];
        for(int i=1;i<=2*n;i++) v[a[i]%2].push_back(i);

        int c = 0;
        for(int i=0;i+1<v[0].size() && c<n-1;i+=2,c++) printf("%d %d\n",v[0][i],v[0][i+1]);
        for(int i=0;i+1<v[1].size() && c<n-1;i+=2,c++) printf("%d %d\n",v[1][i],v[1][i+1]);
    }
}