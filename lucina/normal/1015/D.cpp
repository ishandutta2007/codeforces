#include<bits/stdc++.h>
using namespace std;
const int maxn=3e6+10;
long long n,k,s,f[maxn],d,a;
int main(){
    cin>>n>>k>>s;
    if((n-1)*k<s||k>s){
        printf("NO\n");
        return 0;
    }
    else{
        printf("YES\n");
        a=(s/k);
        for(int i=1;i<=k;i++)
            f[i]=a;
        a=s%k;
        int id=1;
        while(a!=0){
            if(id>k)
            break;
            if(f[id]+a<=n-1){
                f[id]+=a;
                break;
            }
            else{
                a-=(n-1-f[id]);
                f[id]=n-1;
                id++;
            }
        }

        int pt=1;
        for(int i=1;i<=k;i++){
            if(pt+f[i]<=n){
                pt+=f[i];
                cout<<pt<<" ";
            }
            else{
                pt-=f[i];
                cout<<pt<<" ";
            }
        }
        }
        }