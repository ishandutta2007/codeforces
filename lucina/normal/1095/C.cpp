#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,k;
vector<long long> f;
long long p[32];

int main(){
    scanf("%d %d",&n,&k);
    p[0]=1;
    for(int i=1;i<=30;i++){
        p[i]=p[i-1]<<1;
    }
    if(k>n){
        printf("NO\n");
        return 0;
    }
    else{
        int sum=0,x=n,res=0,res2=0,i=0;
        while(true){
            if(sum+x%2+x/2<=k){
                int u=k;
                printf("YES\n");
                for(int j=0;j<f.size();j++){
                    printf("%lld ",f[j]);
                    u--;
                }
                int v=u;
                for(int j=0;j<(x-u);j++){
                    printf("%lld ",p[i+1]);
                    v--;
                }
                while(v--){
                    printf("%lld ",p[i]);
                }
                return 0;
                }
            else{
                res=x%2;
                x=x>>1;
                if(res){
                f.push_back(p[i]);
                }
                i++;
                sum+=res;
            }
            if(x==1&&sum+x%2+x/2>k){
                printf("NO");
                return 0;
            }
        }
    }

}