#include<bits/stdc++.h>
#pragma GCC optimize("O3")
#define maxn 500000
#define maxt 500000
using namespace std;
int n;
int a;
vector<int> dvs[maxt];
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%d",&a);
        for(int j=2;j*j<=a;j++) {
            if(a%j==0) {
                int ti=1;
                while(a%j==0) {
                    ti*=j;
                    a/=j;
                }
                //cout<<i<<" "<<j<<" "<<a<<" "<<ti<<endl;
                dvs[j].push_back(ti);
            }
        }
        if(a!=1) dvs[a].push_back(a);
    }
    long long ans=1;
    for(int i=0;i<=maxt;i++) {
        if(dvs[i].size()==n) {
            sort(dvs[i].begin(),dvs[i].end());
            //cout<<i<<" "<<dvs[i][0]<<" "<<dvs[i][1]<<endl;
            //ans*=dvs[i][0];
            ans*=dvs[i][1];
        }
        if(dvs[i].size()==n-1) {
            sort(dvs[i].begin(),dvs[i].end());
            ans*=dvs[i][0];
        }
    }
    printf("%lld",ans);
	return 0;
}