#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,c,r,t,tt;
char s[maxn];
string g,cute;
void badd(){
    printf(":(");
    exit(0);
}

int main(){
    scanf("%s",s+1);
    n=strlen(s+1);
    for(int i=1;i<=n;i++){
        c+=(s[i]!='a');
    }
    if(c%2)
    badd();
    t=n-c;
    tt=t;
    for(int i=1;i<=n;i++){
        if(s[i]=='a'){
            tt--;
            continue;
        }
        if(r<c/2){
            r++;
            g.push_back(s[i]);
            }
        else if(tt==0){
            cute.push_back(s[i]);
        }
    }
    if(g!=cute)
    badd();
    string ans;
    for(int i=1;i<=n;i++){
        ans.push_back(s[i]);
        if(ans.size()==t+c/2)
        break;
    }
    cout<<ans<<endl;
}