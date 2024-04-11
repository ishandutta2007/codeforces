#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,arr[1010];
map<int,int> mp;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",&arr[i]);

    for(int i=1;i<=n;i++){
        mp[arr[i]]++;
        int fl=0,cnt=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            int c=0;
            while(c<it->second){
                c++,cnt++;
                if(i%2 && cnt%2) fl+=it->first;
                if(i%2==0 && cnt%2==0) fl+=it->first;
            }
        }
        if(fl>m) return !printf("%d",i-1);
    }
    printf("%d",n);
}