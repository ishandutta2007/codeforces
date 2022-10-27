#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
vector<double> st;
int n;
long long d;
double k;
char s[55];
void fin(){
    printf("OVERFLOW!!!");
    exit(0);
}
double pre[maxn];
int main(){
    pre[0]=1;
    double ma=(1ll<<32)-1;
    double x=1;
    double sum=0;
    scanf("%d",&n);
    k=1;
    for(int i=1;i<=n;i++){
        if(sum>ma) fin();
        scanf("%s",s);
        if(s[0]=='a'){
            if(st.empty())sum+=(double)1;
            else{
                k=pre[(int)st.size()];
                if(k>ma)fin();
                else sum+=k;
            }
        }
        else if(s[0]=='e'){
            st.pop_back();
        }
        else{
            scanf("%lld",&d);
            st.push_back(((double)d));
            int l=st.size();
            pre[l]=pre[l-1]*d;
        }
    }
    if(sum>ma)fin();
    printf("%.0f\n",sum);
}