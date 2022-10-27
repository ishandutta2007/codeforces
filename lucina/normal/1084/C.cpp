#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+30,mod=1e9+7;
int a[maxn];
char fuck[maxn];
long long ans;

int main(){
    ans=1;
    scanf("%s",fuck);
    int id=1,ct=0;
    int n=strlen(fuck);
    fuck[n]='b';
    for(int i=0;i<=n;i++){
        if(fuck[i]=='b'){
            a[id++]=ct;
            ct=0;
            while(fuck[i]!='a'&&fuck[i]!='\0'){
                i++;
                }
                i--;
        }
        else if(fuck[i]=='a'){
            ct++;
        }
    }
    for(int i=1;i<=id;i++){
        ans*=(a[i]+1);
        ans%=mod;
    }
    printf("%lld\n",ans-1);


}