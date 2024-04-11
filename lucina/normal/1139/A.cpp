#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
long long ans;
char s[maxn];
int main(){
    int n;
    cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if((s[i]-'0')%2==0){
            ans+=i;
        }
    }
    printf("%lld\n",ans);

}