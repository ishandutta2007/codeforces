#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long n,m,g;
int q;
int s1,e1;
long long s2,e2,l,r;

int main(){
    scanf("%lld%lld%d",&n,&m,&q);
    g=__gcd(n,m);
    long long a=n/g,b=m/g;
    while(q--){
        scanf("%d%lld",&s1,&s2);
        scanf("%d%lld",&e1,&e2);
        if(s1==2){
            l=max(0LL,(s2/b-((s2%b)==0))*b)+1;
            r=(s2/b+((s2%b)!=0))*b;
       ///     cerr<<l<<' '<<r<<'\n';
            if(e1==2){
                printf(((e2>=l)&&(e2<=r))?"YES\n":"NO\n");
            }
            else{
                l=(l-1)/b;
                l*=a;
                l+=1;
                r=r/b;
                r*=a;
           //     cerr<<l<<' '<<r<<'\n';
                printf(((e2>=l)&&(e2<=r))?"YES\n":"NO\n");
            }
        }
        else if(s1==1){
            l=max(0LL,((s2/a)-(s2%a==0))*a)+1;
            r=(s2/a+((s2%a)!=0))*a;
            if(e1==1){
                printf(((e2>=l)&&(e2<=r))?"YES\n":"NO\n");
            }
            else{
                l=(l-1)/a;
                l*=b;
                l+=1;
                r=r/a;
                r*=b;
                printf(((e2>=l)&&(e2<=r))?"YES\n":"NO\n");
            }
        }
    }
}
/*
    Good Luck
        -Lucina
*/