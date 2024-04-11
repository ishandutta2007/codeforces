#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,fl;
ll x,pl=1;
stack<ll> st;
char s[20];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf(" %s",s);
        if(!strcmp(s,"add")){
            if(fl) return !printf("OVERFLOW!!!");
            x+=pl;
        }else if(!strcmp(s,"for")){
            ll a; scanf(" %lld",&a);
            st.push(a);
            if(!fl){
                pl*=a;
                if(pl >= (1ll<<32)) fl = st.size();
            }
        }else{
            if(!fl || (fl && st.size() == fl)){
                pl /= st.top();
                fl=0;
            }
            st.pop();
        }
        
        if(x >= (1ll<<32)) return !printf("OVERFLOW!!!");
    }
    printf("%lld",x);
}