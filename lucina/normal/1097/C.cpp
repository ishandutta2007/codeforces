#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int d[2*maxn];
int n,g;
char s[maxn],e;
long long ans,u;
bool ch;
stack<char> f;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s);
            for(int j=0;s[j]!='\0';j++){
                if(f.empty()){
                    f.push(s[j]);
                }
                else{
                    if(f.top()=='('&&s[j]==')'){
                        f.pop();
                        continue;
                    }
                    else{
                        f.push(s[j]);
                    }
                }
            }
            if(!f.empty()){
                    ch=true;
                    e=f.top();
                    g=f.size();
                    while(!f.empty()){
                        if(f.top()!=e)
                            ch=false;
                            f.pop();
                    }
                    if(ch){
                        if(e=='(')
                            d[g]++;
                        else
                            d[int(5e5)+1+g]++;
                    }
                }
                else{
                    d[0]++;
                }
    }
    for(int i=1;i<=int(5e5);i++){
        u=min(d[i],d[i+int(5e5)+1]);
        ans+=u;
    }
    ans+=(d[0])/2;
    printf("%lld\n",ans);
}