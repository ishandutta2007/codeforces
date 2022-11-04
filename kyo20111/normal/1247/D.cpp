#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,chk[100100],a[100100];
map<vector<pair<int,int>>, int> mp;
ll o, ans;
int main(){
    for(int i=2;i<=100000;i++){
        if(chk[i]) continue;
        for(int j=i;j<=100000;j+=i) chk[j] = i;
    }

    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",a+i);
    }
 
    for(int i=1;i<=n;i++){
        int b = a[i];
 
        map<int,int> mp2;
        while(b != 1){
            mp2[chk[b]]++;
            b /= chk[b];
        }

        vector<pair<int,int>> v,v2;
        int fl = 0;
        for(auto it=mp2.begin();it!=mp2.end();it++){
            if(it->second % k){
                fl = 1;
                v.push_back({it->first, it->second % k});
                v2.push_back({it->first, k - (it->second % k)});
            }
        }

        if(!fl){
            ans += o++;
            continue;
        }

        if(mp.count(v2)) ans += mp[v2];
        mp[v]++;
    }
 
    printf("%lld",ans);
}