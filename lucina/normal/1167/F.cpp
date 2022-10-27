#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,mod=1e9+7;
int u,v,n;
vector<pair<int,int>> a;
inline int add(int a, int b) {
  a += b;
  if (a >= mod) a -= mod;
  return a;
}
inline int sub(int a, int b) {
  a -= b;
  if (a < 0) a += mod;
  return a;
}
inline int mul(int a, int b) {
  return (int) ((long long) a * b % mod);
}

struct bit{
    int b[maxn];
    void update(int idx,int val){
        while(idx<=n){
            b[idx]=add(b[idx],val);
            idx+=(idx&(-idx));
        }
        return;
    }
    int get(int idx){
        int sum=0;
        while(idx>0){
            sum=add(sum,b[idx]);
            idx-=(idx&(-idx));
        }
    return sum;
    }
}f1,f2;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&u);
        a.push_back(make_pair(u,i));
    }
    sort(a.begin(),a.end());
    int ans=0;
    for(auto i:a){
        u=mul(i.second,n-i.second+1);
        u=add(u,mul(f1.get(i.second),n-i.second+1));
        u=add(u,mul(sub(f2.get(n),f2.get(i.second)),i.second));
        ans=add(ans,mul(u,i.first));
        f1.update(i.second,i.second);
        f2.update(i.second,n-i.second+1);
    }
    printf("%d\n",ans);
}