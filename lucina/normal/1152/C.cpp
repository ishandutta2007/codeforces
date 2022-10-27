#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long base;
vector<int> d,f;
int a,b,g,k,ans;
int main(){
    scanf("%d%d",&a,&b);
    if(a<b){
    swap(a,b);
    }
    g=a-b;
    base=(1ll*a*b)/(__gcd(a,b));
    if(g==0){
        printf("%d",0);
        return 0;
    }
    int x=sqrt(g);
    for(int i=x;i>=2;i--){
        if(g%i==0){
            if(g!=i*i)
            d.push_back(g/i);
            d.push_back(i);
        }
    }
    d.push_back(1);
    d.push_back(g);
    sort(d.begin(),d.end());
    for(int i:d){
        k=(-b)%i;
        k=(k+i)%i;
        f.push_back(k);
    }
    long long n;
    sort(f.begin(),f.end());
    for(int i:f){
        n=1ll*(a+i)*(b+i)/__gcd(a+i,b+i);
        if(n<base){
            base=n;
            ans=i;
        }
    }
    printf("%d\n",ans);
}